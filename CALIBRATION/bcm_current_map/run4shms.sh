#!/bin/bash

#list=$1
list="/u/group/c-csv/hdbhatt/test_april2020_branch/hallc_replay_sidis_fall18/CALIBRATION/bcm_current_map/springrunlist.txt"

while read line
do	
#	echo "$line"
	cd /u/group/c-csv/hdbhatt/test_april2020_branch/hallc_replay_sidis_fall18/CALIBRATION/bcm_current_map/
	echo $pwd
	root -b -l -q<<EOF
        .x run.C(6464)

#	.x run.C("$line")
EOF

#echo "$line"


done < "$list"






















#fname=/lustre19/expphy/volatile/hallc/spring17/hdbhatt/group/ROOTfiles/coin_replay_production_${line}_-1.root

#fname=/home/cdaq/hallc-online/hallc_replay/ROOTfiles/shms_replay_production_${line}_-1.root


#root -b<<EOF
#.x run.C(${line})
#EOF

#[ ! -d "shms" ] && `mkdir shms`

#mv bcmcurrent* ./shms/

#done < ${list}
