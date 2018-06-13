cd base-3.16.1
make -j
cd ..


cd support

cd ipac
make -j
cd ..

cd seq
make
cd ..

cd asyn
make -j
cd ..

cd autosave
make -j
cd ..

cd busy
make -j
cd ..

cd sscan
make -j
cd ..

cd calc
make -j
cd ..

cd motor
make -j
cd ..

cd ..
cd ioc 
make -j 
cd iocBoot/iocsm
make envPaths
cd ..
