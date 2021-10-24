//       This code was produced by FUZZGEN, the Fuzzy 
//       Logic Code Generator from Alston Software Labs. 
// 
// 
// The File example1.VAR contains the 
// variable list used...
 
// FUNCTION PROTOTYPES
 
void ReadVarsIn(void);     // read in variables 
float InputDataTest(float, float, float, float, int, float);
float InputTest(float);


// GLOBAL VARIABLES
 
float Left[10], Right[10], LeftA[10], RightA[10];
int Type[10], TotalSets;
FILE *fp;


//  This routine reads in the variables as written to disk.
//
void ReadVarsIn(void)
{
  int j  =1;
 
  if(fp = fopen("example1.VAR","r")) == NULL
    exit(0);
  while(!feof(fp)){
     fscanf(fp,"%f", Left[j]);
     fscanf(fp,"%f", Right[j]);
     fscanf(fp,"%f", LeftA[j]);
     fscanf(fp,"%f", RightA[j]);
     fscanf(fp,"%d", Type[j++]);
  }
  fclose(fp);
  TotalSets = --j;
}
 
 
//  The following routine tests the inputs
//  You may want to rename it if you are using multiple
//  FL decisions from this product...
 
float InputDataTest(float lo, float hi, float apL
                    float apR, int typ, float INPUTDATA)
{
   float BaseL, BaseR, RatioL = 0, RatioR = 0;
 
   // exit immediately if data out of bounds...
   if(INPUTDATA < lo || INPUTDATA > Hi)  return(0);
   if(INPUTDATA >= lo && INPUTDATA <= hi){
   // if BOOLEAN and we are in bounds 
   if(typ == 3) return(100);
   // otherwise we figure out membership as a percentage
   BaseL = apL - lo;
   BaseR = hi - ap2;
   if(BaseL > 0) RatioL = (100 / BaseL);
   if(BaseR > 0) RatioR = (100 / BaseR);
   if(typ == 1){                // triangular
      if(INPUTDATA <= apL)      // left of apex
         return((INPUTDATA - BaseL) * RatioL);
      Else
         return((BaseR - INPUTDATA) * RatioR);
   }
   Else{                        // trapezoidal
      if(INPUTDATA >= apL && INPUTDATA <= apR) return(100);
      if(INPUTDATA <= apL)
         return((INPUTDATA - BaseL) * RatioL);
      if(INPUTDATA > apR)
         return((BaseR - INPUTDATA) * RatioR);
   }
}
 
 
 
//  This Function Loops through the sets to determine the
//  the set with the highest membership.
 
float InputTest(float INPUTDATA)
{
  int i, State = 0;
  float Tester, PlaceHold = 0;
 
  for(i = 1; i < TotalSets; i++){
      Tester = InputDataTest(Left[i], Right[i], LeftA[i], RightA[i], Type[i]);
      if(PlaceHold > Tester){
         PlaceHold = Tester;
         State = i;
      }
  }
  return(State);
}
 
 
