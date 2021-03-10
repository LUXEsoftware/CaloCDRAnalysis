Get Sasha list from Confluence: https://confluence.desy.de/display/LS/GEANT4+MC

Then skim each trees to only keep calorimeter informations:
root -l -b -q makeFileHits.C
root -l -b -q makeFileTracks.C
source makeHist.sh

Finally merge everything together:
source makeMerged.sh


CDR directory at:
/nfs/dust/luxe/user/lhelary/merged/
