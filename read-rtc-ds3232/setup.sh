#! /bin/bash
if [ -z "$BASH_VERSION" ]; then exec bash "$0" "$@"; fi;
# setup.sh
# Copyright (C) 2014 spaceconcordia <spaceconcordia@mustang>
#
# Distributed under terms of the MIT license.
#
# colors: echo -e "${red}Text${NC}"
NC='\e[0m';black='\e[0;30m';darkgrey='\e[1;30m';blue='\e[0;34m';lightblue='\e[1;34m';green='\e[0;32m';lightgreen='\e[1;32m';cyan='\e[0;36m';lightcyan='\e[1;36m';red='\e[0;31m';lightred='\e[1;31m';purple='\e[0;35m';lightpurple='\e[1;35m';orange='\e[0;33m';yellow='\e[1;33m';lightgrey='\e[0;37m';yellow='\e[1;37m';

declare -a SysReqs=('dialog' 'whiptail')
for item in ${SysReqs[*]}; do command -v $item >/dev/null 2>&1 || { echo >&2 "I require $item but it's not installed.  Aborting."; exit 1; }; done

set -e # abort on error

confirm () { 
    read -r -p "${1:-[y/N]} [y/N] " response
    case $response in
        [yY][eE][sS]|[yY]) 
            true
            ;;
        *)
            false
            ;;
    esac
}

fail () {
    echo -e "${red}Aborting... $1${NC}" 
    exit 1
}

quit () {
    echo -e "Exiting... $1" 
    exit 0
}

usage="${yellow}usage: setup.sh [project_name (optional)]${NC}"
#if [ $# -eq 0 ]; then echo -e "No arguments supplied... $usage"; fi 

ORIG_TEXT="read-rtc-ds3232"
CURRENT_DIR=${PWD##*/}

search-and-replace () {
  echo -e "${yellow}find ./ -type f -exec sed -i 's|$ORIG_TEXT|$1|g' {} \;${NC}"
  find ./ -type f -exec sed -i "s|\"$ORIG_TEXT\"|\"$1\"|g" {} \;
  find ./ -type f -exec sed -i "s|"$ORIG_TEXT"|"$1"|g" {} \;
  echo -e "${yellow}mv src/{$ORIG_TEXT,$1}.cpp${NC}"
  mv src/{"$ORIG_TEXT","$1"}.cpp   
  echo -e "${yellow}mv gtest/{"$ORIG_TEXT","$1"}_test.cpp${NC}"
  mv gtest/{"$ORIG_TEXT","$1"}_test.cpp
}

if confirm "Rename project and its associated declarations to $CURRENT_DIR" ; then
  search-and-replace $CURRENT_DIR
else
  echo "Naming convention: action-system-hardware_id - i.e. read-pwr-ina219"
  echo "Enter the name of the job:"
  read JOBNAME
  confirm "Are you sure you wish to name this job $JOBNAME?" && search-and-replace $JOBNAME
fi

quit # exit cleanly
