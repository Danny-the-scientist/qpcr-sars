//Incoming data from previous modules contains raw read outputs from BioRad machines

SARS_Average_SQ := "NA";//SQ meaning starting quantity of measured gene for SARS virus
numerator := 0;
denominator := 0;

for #i in 1 .. ArrayNumvalues(SARS_Starting_Quantity)//Looping based on technical replicates on the qPCR plate
    loop
    if SARS_Starting_Quantity[#i] ne "" and SARS_Starting_Quantity[#i] != 0 then//Starting quantity was calculated and is a non-zero number
        numerator := SARS_Starting_Quantity[#i] + numerator;//increase numerator value
        denominator := denominator + 1;//iterate denominator
    end if;
end loop;

if denominator > 0 then
    SARS_Average_SQ := numerator/denominator;//if capable, calculate the average from the updated numerator and denominators
end if;
sample_keep := "Yes";//this particular program brings in lots more data than what's actually used; later on the sample_keep is used to filter unwanted ones out
