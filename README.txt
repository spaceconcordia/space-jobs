job-priority.txt

Naming Convention
action-system-hardware_id - e.g. read-pwr-ina219

* jobs started

Priority One Jobs (need before launch)
- Enable nichrome-wire heater for Antenna Deployment (diable-AHRM, enable-AHRM) * [TODO COMBINE THESE JOBS]
- ECU Thermal Ambient Sensors (ElecbaynPayload) *
- Read Magnotometer - magnetic field in <x,y,z> (MagReading) * [read-acs-hmc5883l]
- Read current flowing into/outof voltage at + terminal at battery pack, and auto-calc power from both (read-pwr-ina219) [System Checkout] *
- Multiplexed voltmeter, 8xVM_inputs, 4 unused, remaining battery pack thermistor voltage 1&2, solar panel voltage 1&2  (read-pwr-ad7998) * [System Checkout]
- Solar Panel Temperature Sensor (SolarPanelTemperature_Sensor) *
- Enable 3.3V line
- Enable 9V line
- Payload - WORK WITH SVETLANA
- SYSTEMS
  - no memory check req'd
  - watchdog (soft-reset (Shawn S), hard-reset (Ty))
  - LEOP Launch_Early_Operations_Phase_ !!
  - Health (Post-commissioning phase) Option for full telemetry or Go_or_no_go_
  - Make a counter for how many reboots, and shutdowns

Priority Two Jobs (upload after launch)

TBD during functional testing
- Interrupt on line failure
