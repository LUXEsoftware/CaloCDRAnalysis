#Setup:

Create two directories: 
e_laser
g_laser

Each should contain 3 directories:
input
output
plots

The input directories will contain simulation files with single particle electrons for each energy studied.

#Run:

First need to run CaloHitsBkg analysis to obtain background files for e_laser and g_laser. 

Once done, run to create output files:
source run.sh

Then run ploting macros to create output files:
Calorimeter_elaser_EnergyResolution_Macro.C
Calorimeter_elaser_ShowerEnergyDeposition_Macro.C
Calorimeter_elaser_sOsb_Macro.C
Calorimeter_glaser_EnergyResolution_Macro.C
Calorimeter_glaser_ShowerEnergyDeposition_Macro.C
Calorimeter_glaser_sOsb_Macro.C


# CDR analysis located at:

/nfs/dust/luxe/user/lhelary/Louis/CaloHitsAnalysis/calohitsanalysis
