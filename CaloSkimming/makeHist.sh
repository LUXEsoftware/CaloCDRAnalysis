#hadd all the histograms in list provided by Sasha:  
hadd -T backgroundFastSim_Hist1.root `more list_root_hics_background_fast_9f6b6590_34_35.txt` 


#If too much files in the list (max ~10k files can be processed that way), first split the list: 
#split -l 7500 list_root_hics_background_fast_9f6b6590_34_35.txt
