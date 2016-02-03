//http://liris.cnrs.fr/~crocaber/3Bim/

// ===========================================================================
//                                  Includes
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>

#include "DLA.h"
#include "ImagePPM.h"


using namespace std;


// ===========================================================================
//                            Function declarations
// ===========================================================================


// ===========================================================================
//                                    MAIN
// ===========================================================================

int main(int argc,char* argv[]){
	srand(time(NULL));
	DLA* dla1 = new DLA(100,75,75);
	dla1->mainMethod();
	
	ImagePPM* miracle = new ImagePPM(100,dla1->tab);
	miracle->save("test.ppm");
		
	delete dla1;
	delete miracle;
	
	return 0;
}


