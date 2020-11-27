R__LOAD_LIBRARY(ScalerCalib_C)

//void run(string fin="fin.root", string spec_name="P")
void run(int runNum)




{

string spec_name="P";
string path="/lustre19/expphy/volatile/hallc/spring17/hdbhatt/group/ROOTfiles/test-april2020-branch1/";
string fin = Form("%scoin_replay_production_%d_-1.root",path.c_str(),runNum);


 
  //H: HMS, P: SHMS
  ScalerCalib scalib(spec_name);
  scalib.SetInputFile(fin);
  scalib.SetPrintFlag(1); //0: bcm1 and bcm2 only, 1: all
  scalib.Run();

}



