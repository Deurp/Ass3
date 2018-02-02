#mv A2.tar.gz oldtar/A2_oldtar.tar.gz
#tar -czf A2.tar.gz A2
make
./galsim 4 input_data/circles_N_4.gal 2 0.5 0
#./galsim 2 Makefile 2 0.5 0