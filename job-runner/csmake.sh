#!/bin/bash
#**********************************************************************************************************************
#
# AUTHORS : Space Concordia 2014, Joseph
#
# FILE : cscomtest.sh
# 
# PURPOSE : csmake template
#           -g      Group
#           -q      build for Q6
#           -n      TestName
#           -s      skip the tests
#           -u      usage
#           -v      verbose (to get all DEBUG output)
# 
#       ex. ./cscomtest.sh                  =>   run ALL the tests
#           ./cscomtest.sh -g deletelog     =>   run ALL deletelog tests
#           ./cscomtest.sh -n nameOfTheTest
#
#**********************************************************************************************************************

ALLTESTS="./bin/AllTests"
ARGUMENTS=""
GROUP=""
TODEVNULL=1
MBCC=0
MULTIPLE_RUN=1
CLEAN=0
SKIP_TEST=0
GROUP_LIST=() # insert the group of the test here.


#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#
# NAME : usage
#
#------------------------------------------------------------------------------
usage()
{
    echo "usage : cscomtest.sh  [-u] [-g testGroup] [-n testName] [-m numberOfRuns][-v][-s]"
    echo "          -c clean before build"
    echo "          -m numberOfRuns : run the specified tests 'numberOfRuns' times and stop if error" 
    echo "          -q build for Q6"
    echo "          -s skip the tests"
    echo "          -u usage"
    echo "          -v verbose : to get all DEBUG info (N.B. DEBUG info can be turned on/off in the makefile ... -DDEBUG)"
    printf "%s" "          -g group   : one of those -> " 
    for gr in ${GROUP_LIST[@]}; do
        printf "%s " $gr
    done
    echo
}

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#
# Parsing command line arguments
#
#------------------------------------------------------------------------------
argType=""
while getopts "cqg:n:uvm:s" opt; do
    case "$opt" in
        c) CLEAN=1
        ;; 
        g) GROUP=$OPTARG
        ;;
        m) MULTIPLE_RUN=$OPTARG
        ;;
        n) SINGLE_TEST="-n $OPTARG" 
        ;;
        q) MBCC=1
        ;;
        s) SKIP_TEST=1 
        ;;
        u)
            usage
            exit 0;
        ;;
        v) TODEVNULL=0 ;;
    esac
done

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#
# Test groups
#
#------------------------------------------------------------------------------
if [ "$GROUP" != "" ]; then
    case $GROUP in 
        'getlog')       ARGUMENTS="-g GetLogTestGroup" ;;  # <----- this is just as an example, add your test groups!
    esac
fi

ARGUMENTS="$ARGUMENTS $SINGLE_TEST" 


#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#
# Clean
#
#------------------------------------------------------------------------------
if [ $CLEAN -eq 1 ]; then
    echo ""
    echo "=== Clean ==="
    make clean || exit 1
fi

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#
# Build x86 
#
#------------------------------------------------------------------------------
echo ""
echo "=== Build x86 ==="
make buildBin 

if [ $? -ne 0 ]; then
    echo -e "\e[31m Build x86 failed\e[0m"
    exit -1
else
    echo -e "\e[32m Build x86 success!\e[0m"
fi

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#
# Build mbcc 
#
#------------------------------------------------------------------------------
if [ $MBCC -ne 0 ]; then
    echo ""
    echo "=== Build mbcc ==="
    make buildQ6 

    if [ $? -ne 0 ]; then
        echo -e "\e[31m Build mbcc failed\e[0m"
        exit -1
    else
        echo -e "\e[32m Build mbcc success!\e[0m"
    fi
fi

#
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#
# PURPOSE : run/build the tests
#
#-----------------------------------------------------------------------------
if [ $SKIP_TEST -eq 0 ]; then
    echo ""
    echo "=== Build tests ==="
    csmaketest_filepath=`find . -type f -name 'csmaketest.sh'`
    if [ $csmaketest_filepath ] ; then
        csmaketest_file=`basename "$csmaketest_filepath"`
        csmaketest_dir=`dirname "$csmaketest_filepath"`
        cd $csmaketest_dir
        bash $csmaketest_file
    else 
        make test

        if [ $? -ne 0 ]; then
            echo -e "\e[31m Build tests failed\e[0m"
            exit -1
        else
            echo -e "\e[32m Build tests success!\e[0m"
        fi

        echo ""
        echo "=== Run tests ==="

        counter=0

        while [ $counter -lt $MULTIPLE_RUN ]; do
            if [ $TODEVNULL -ne 0 ]; then
                echo $ALLTESTS $ARGUMENTS 2>/dev/null
                $ALLTESTS $ARGUMENTS  2>/dev/null
            else
                echo $ALLTESTS $ARGUMENTS 
                $ALLTESTS $ARGUMENTS  
            fi

            if [ $? -ne 0 ]; then
                echo -e "\e[31m UTest Failure!\e[0m"
                exit 1
            else 
                echo -e "\e[32m UTest Success!\e[0m"
            fi

            sleep 1

            counter=$(($counter+1))
        done
    fi
fi

