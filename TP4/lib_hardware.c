#include "lib_hardware.h"

/*format all the disk*/
void frmt () {
    /*catch the number of sectors and cylinders*/
    int nbSector, nbCylinder,i,j;
    _out(HDA_CMDREG,CMD_DSKINFO);
    nbSector = (_in(HDA_DATAREGS+2)<<8) + _in(HDA_DATAREGS+3);
    nbCylinder = (_in(HDA_DATAREGS)<<8) + _in(HDA_DATAREGS+1);
    
    /*format the disk for all sector in all cylinders*/
    for(j=0;j<nbCylinder;j++){
	for (i=0;i<nbSector;i++){
	  format_sector(j,i,0);
	}
    }
}

/*print the content of a sector*/
void dmps (int cylinder, int sector){
    unsigned char buf[SECTORSIZE];

    read_sector(cylinder, sector, buf);

    /*Print the sector*/
    dump(buf,SECTORSIZE,1,0);
}

void empty_it(){
  return;
}

void chk_hda(){
  int sectorsize;
  _out(HDA_CMDREG,CMD_DSKINFO);
  sectorsize = (_in(HDA_DATAREGS+4) << 8) +  _in(HDA_DATAREGS+5);
  assert(sectorsize==SECTORSIZE);
}

