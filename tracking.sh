#! /bin/tcsh
set k =0.0
set old =0
while [ k < 100 ]

new = $old+5

sed -i s/'pxt_track_criterion = $old'/'pxt_track_criterion = $new'/g PARAM/SHMS/GEN/test.param

do

./hcana -q 'SCRIPTS/COIN/PRODUCTION/replay_production_coin_hElec_pProt.C( 7671, 20000)'

mv 









#sed -i s/'pxt_track_criterion = 100.0'/'pxt_track_criterion = 10000.0'/g PARAM/SHMS/GEN/test.param
