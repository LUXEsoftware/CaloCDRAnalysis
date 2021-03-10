for i in {1..17};do root runCaloHitsAnalysis.C\($i,1,\"e_laser\",\"CaloHitsBkg/Fast_background_eLaser_final.root\"\);done
for i in {1..17};do root runCaloHitsAnalysis.C\($i,0,\"e_laser\",\"CaloHitsBkg/Fast_background_eLaser_final.root\"\);done
