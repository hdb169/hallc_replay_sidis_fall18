#!/bin/bash

#list=$1
list="/u/group/c-csv/hdbhatt/test_april2020_branch/hallc_replay_sidis_fall18/CALIBRATION/bcm_current_map/run_mark.txt"


while read line
do

#fname=/lustre19/expphy/volatile/hallc/spring17/hdbhatt/group/ROOTfiles/test-april2020-branch1/coin_replay_production_${line}_-1.root

fname=/lustre19/expphy/volatile/hallc/spring17/hdbhatt/group/ROOTfiles/datasimc/coin_replay_production_${line}_-1.root


root -l -b -q<<EOF
#root -b<<EOF

.x run.C("${fname}", "P")
EOF

#[ ! -d "shms" ] && `mkdir shms`

#mv bcmcurrent* ./shms/

done < ${list}
