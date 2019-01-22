/*
 ============================================================================
 Name        : Adjusted.c
 Author      : Mikele Fakadu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
#include "Propagate.h"
#include "Basic.h"
#include "Fileio.h"
#include "Vector.h"
#include "Check.h"
#include "Datefun.h"
#include "Matrix.h"
#include "Vector.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define CUBE_ROOT(X) (exp(log(X)/ 3.))

int main(void){

	double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
    printf("\n Station data being imported:\n\n");
    Station *stn = (Station*) malloc(sizeof(Station));
    ReadStationFile(stn, '0');
    printf("Finished\n\n");
    int sf;
    for (sf = 0; sf < 1;){
	printf("\nSelect one of the options:\n");
	printf("1) View the data for the station file\n");
	printf("2) Edit the data for the station file\n");
	printf("3) continue\n\n");
	int input1;
	printf("Entry: ");
	fflush(stdout);
	scanf("%d", &input1);
	if (input1 == 1){
	    printf("\nContents of the Station File:\n");
	    printf("-> Name: %s\n", stn->name);
	    printf("-> Station Latitude: %f\n", stn->stnlat);
	    printf("-> Station Longitude: %f\n", stn->stnlong);
	    printf("-> Station Altitude: %f\n", stn->stnalt);
	    printf("-> UTC Offset: %f\n", stn->utc_offset);
	    printf("-> Azimuth Elevation nlim: %d\n", stn->az_el_nlim);
	    printf("-> Azimuth Elevation Limit Azimuth: %f\n", stn->az_el_lim.az);
	    printf("-> Azimuth Elevation Limit Elevation Min: %f\n", stn->az_el_lim.elmin);
	    printf("-> Azimuth Elevation Limit Elevation Max: %f\n", stn->az_el_lim.elmax);
	    printf("-> Station Azimuth Speed Max: %f\n", stn->st_az_speed_max);
	    printf("-> Station Elevation Speed Max: %f\n", stn->st_el_speed_max);
	}
	if(input1 == 2){
	  //  printf("\n1 name\n");
	    printf("2) Edit the stnlat\n");
	    printf("3) Edit the stnlong\n");
	    printf("4) Edit the stnalt\n");
	    printf("5) Edit the utc_offset\n");
	    printf("6) Edit the az_el_nlim\n");
	    printf("7) Edit the az_el_nlim.az\n");
	    printf("8) Edit the az_el_nlim.elmin\n");
	    printf("9) Edit az_el_nlim.elmax\n");
	    printf("10) Edit st_az_speed_max\n");
	    printf("11) Edit st_el_speed_max\n");
	    printf("\nSelect one of the above options: ");
	    int num2;
	    fflush(stdout);
	    scanf("%d", &num2);
	    printf("\n");
/*	    if(num2 == 1){
		printf("name entry: ");
		char *n;
		fflush(stdout);
		scanf("%c", n);
	    }*/
	    if(num2 == 2){
		printf("Entry for stnlat: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		stn->stnlat = n;
	    }
	    if(num2 == 3){
		printf("Entry for stnlon: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		stn->stnlong = n;
	    }
	    if(num2 == 4){
		printf("Entry for stnalt: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		stn->stnalt = n;
	    }
	    if(num2 == 5){
		printf("Entry for utc_offset: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		stn->utc_offset = n;
	    }
	    if(num2 == 6){
		printf("Entry for az_el_nlim: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		stn->az_el_nlim = n;
	    }
	    if(num2 == 7){
		printf("Entry for az_el_lim.az: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		stn->az_el_lim.az = n;
	    }
	    if(num2 == 8){
		printf("Entry for az_el_lim.elmin: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		stn->az_el_lim.elmin = n;
	    }

	    if(num2 == 9){
		printf("Entry for az_el_lim.elmax: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		stn->az_el_lim.elmax= n;
	    }

	    if(num2 == 10){
		printf("Entry for st_az_speed_max: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		stn->st_az_speed_max = n;
	    }
	    if(num2 == 11){
		printf("Entry for st_el_speed_max: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		stn->st_el_speed_max = n;
	    }
	}
	if (input1 == 3){sf++;}
    }
    printf("\nThe TLE file is being imported:\n\n");
    char *file = "TLE.txt";
    Satellite sats[32];
    ReadNoradTLE(sats, file);
    printf("Finished\n");
    int x;
    for(x = 0;x < 1;){
	printf("\n\nSelect one of the following options:\n");
	printf("1) View the TLE data\n");
	printf("2) Edit TLE data\n");
	printf("3) Continue\n\n");
	int input2;
	printf("Entry: ");
	fflush(stdout);
	scanf("%d", &input2);
	if(input2 == 1){
	    printf("\nInput the satellite number for the satellite you would like to track: ");
	    int num;
	    fflush(stdout);
	    scanf("%d", &num);
	    printf("\n The following is the information for sat number %d:\n", num);
	    printf("\n The satellites name is: %s", sats[num].name);
	    printf(" The refepoch is: %f\n", sats[num].refepoch);
	    printf(" The incl is: %f\n", sats[num].incl);
	    printf(" The raan is: %f\n", sats[num].raan);
	    printf(" The eccn is: %f\n", sats[num].eccn);
	    printf(" The argper: is %f\n", sats[num].argper);
	    printf(" The meanan is: %f\n", sats[num].meanan);
	    printf(" The meanmo is: %f\n", sats[num].meanmo);
	    printf(" The ndot is: %f\n", sats[num].ndot);
	    printf(" The nddot6 is: %f\n", sats[num].nddot6);
	    printf(" The bstar is: %f\n", sats[num].bstar);
	    printf(" the orbitnum is: %f\n", sats[num].orbitnum);
	}
	if(input2 == 2){
	    printf("\nInput the satellite number for the satellite you would like to edit: ");
	    int num;
	    fflush(stdout);
	    scanf("%d", &num);
	    printf("\n1) The satellites name\n");
	    printf("2) The refepoch\n");
	    printf("3) The incl\n");
	    printf("4) The raan\n");
	    printf("5) The eccn\n");
	    printf("6) The argper\n");
	    printf("7) The meanan\n");
	    printf("8) The meanmo\n");
	    printf("9) The ndot\n");
	    printf("10) The nddot6\n");
	    printf("11) The bstar\n");
	    printf("12) The orbitnum\n");
	    printf("\nSelect the option that you would like to edit: ");
	    int num2;
	    fflush(stdout);
	    scanf("%d", &num2);
	    printf("\n");
	    if(num2 == 1){
		printf("Entry for the satellite name: ");
		char *n;
		fflush(stdout);
		scanf("%c", n);
		//sats[num].name = n;
	    }
	    if(num2 == 2){
		printf("Entry for the refepoch: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		sats[num].refepoch = n;
	    }
	    if(num2 == 3){
		printf("Entry for the incl: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		sats[num].incl = n;
	    }
	    if(num2 == 4){
		printf("Entry for the raan: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		sats[num].raan = n;
	    }
	    if(num2 == 5){
		printf("Entry for the eccn: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		sats[num].eccn = n;
	    }
	    if(num2 == 6){
		printf("Entry for the argper: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		sats[num].argper = n;
	    }
	    if(num2 == 7){
		printf("Entry for the meanan: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		sats[num].meanan = n;
	    }
	    if(num2 == 8){
		printf("Entry for the meanmo: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		sats[num].meanmo = n;
	    }
	    if(num2 == 9){
		printf("Entry for the ndot: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		sats[num].ndot = n;
	    }

	    if(num2 == 10){
		printf("Entry for the nddot6: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		sats[num].nddot6 = n;
	    }

	    if(num2 == 11){
		printf("Entry for the bstar: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		sats[num].bstar = n;
	    }
	    if(num2 == 12){
		printf("Entry for the orbitnum: ");
		double n;
		fflush(stdout);
		scanf("%lf", &n);
		sats[num].orbitnum = n;
	    }
	}
	if(input2 == 3){x++;}
    }

    printf("\nOpening the file linkinfo.dat, please wait.\n\n");
    printf("Finished\n");

    printf("\nOpening the tracking file, please wait.\n\n");
    FILE *fp = fopen("tracking_sched.txt","r+");

    char line1[50];
    char line2[50];
    char line3[31];
    fgets(line1, 50, fp);
    fgets(line2, 50, fp);
    fgets(line3, 31, fp);

    fclose(fp);


    char date_start[20], date_stop[20], time_step[6];

    strncpy(date_start, line1+26, 19);
    strncpy(date_stop, line2+25, 19);
    strncpy(time_step, line3+24, 5);
    printf("The start date is: %s\n",date_start);
    printf("The stop date is: %s\n",date_stop);
    printf("The time step is: %s\n",time_step);

    printf("\nNow computing the AOS and LOS, please wait.\n");

    double step;
    step = atof(time_step);

    double JulianDateStart, JulianDateStop;

    JulianDateStart = dat2jd(date_start);
    JulianDateStop = dat2jd(date_stop);

    char *NAME[31];
    double AOS[31], LOS[31];
    int NUM[31];
    int num = 0;

    double ss[31], fD[31];
    for(int j=0; j<31; j++){

	double currentTime;
	currentTime = JulianDateStart;
	int acquired=0;
	int lost = 0;

	for( ;currentTime<JulianDateStop; currentTime = currentTime+frcofd(0,0,step)){
	    double mA, mM;
	    double satEpoch = sats[j].refepoch;
	    double mA0 = sats[j].meanan;
	    double nMM = sats[j].meanmo;
	    double ndMM = sats[j].ndot;
	    double n2dMM = sats[j].nddot6;
	    mean_anomaly_motion(&mA, &mM, currentTime, jdatep(satEpoch), mA0, nMM, ndMM, n2dMM);
	    double mMrev=mM/(2*PI);

	    double eccAnom = KeplerEqn(mA, sats[j].eccn);

	    Vector *eciPos, *eciVel;
	    eciPos = (Vector*)malloc(sizeof(Vector));
	    eciVel = (Vector*)malloc(sizeof(Vector));

	    double sMA = CUBE_ROOT(398600.4418/(4*PI*PI*mMrev*mMrev));
	    sat_ECI(eciPos, eciVel, sats[j].eccn, eccAnom, sMA, sats[j].raan*PI/180,
		    sats[j].argper*PI/180, sats[j].incl*PI/180, mM);
	    Vector *ecfPos, *ecfVel;
	    ecfPos = (Vector*)malloc(sizeof(Vector));
	    ecfVel = (Vector*)malloc(sizeof(Vector));

	    double thetat = THETAJ(currentTime,JulianDateStart);
	    sat_ECF(ecfPos, ecfVel, thetat, eciPos, eciVel);
	    Vector *stnPos, *rtPos, *rtVel;
	    stnPos = (Vector*)malloc(sizeof(Vector));
	    station_ECF(stnPos, stn->stnlong, stn->stnlat, stn->stnalt);
	    rtPos = (Vector*)malloc(sizeof(Vector));
	    rtVel = (Vector*)malloc(sizeof(Vector));
	    range_ECF2topo(rtPos, rtVel, *stnPos, ecfPos, ecfVel, stn->stnlong, stn->stnlat);

	    double az;
	    double el;
	    double azV;
	    double elV;
	    LookAngles *LA =(LookAngles*) malloc(sizeof(LookAngles));
	    range_topo2look_angles(LA, az, el, azV, elV, rtPos, rtVel);
	    ss[num] = linkstrength(sqrt(rtPos->x*rtPos->x+rtPos->y*rtPos->y+rtPos->z*rtPos->z));
	    if (LA->elevation <= stn->az_el_lim.elmax && LA->elevation >= stn->az_el_lim.elmin && acquired == 0){//Go in to this loop if the satellite is acquired.

		NUM[num] = j;
		NAME[num] = sats[j].name;
		NAME[num][strlen(NAME[num])-1] = '\0';
		NAME[num][strlen(NAME[num])-2] = '\0';
		AOS[num] = currentTime;
		acquired = 1;
	    }
	    if(LA->elevation >= stn->az_el_lim.elmax && LA->elevation <= stn->az_el_lim.elmin && acquired==1){// Go in to this loop if the satellite is lost.
		LOS[num] = currentTime;
		lost = 1;
		break;
	    }
	}
	if(acquired==1)
	    {
	    if(lost==0)
		{
		LOS[num] = JulianDateStop;
		}num++;
	    }
    }
    printf("\nComplete\n\n");

    FILE *filepoint;
    filepoint = fopen("AOSLOS.txt", "w+");
    printf("Sat #:	 |	Sat Name:	 |		AOS:	  |		LOS:	 |	Min. ExpectedLevel (dBm):\n");
    fprintf(filepoint, "Sat #:		|	Sat Name:		|			AOS:			|		LOS:			|		Min. ExpectedLevel (dBm):\n");
    for(int i=0;i<num;i++){
	printf("%d	 %s %s 	", NUM[i], NAME[i], jd2dat(AOS[i]));
	printf("%s", jd2dat(LOS[i]));
	printf("\t%f\n",ss[i]);
	fprintf(filepoint, "%d	 	%s	%s 	", NUM[i], NAME[i], jd2dat(AOS[i]));
	fprintf(filepoint, "%s", jd2dat(LOS[i]));
	fprintf(filepoint," 	%f\n",ss[i]);
    }
    fclose(filepoint);

    printf("\n\nInput the 'sat #' for the satellite to be tracked: ");
    int satNum;
    fflush(stdout);
    scanf("%d", &satNum);
    Satellite sat = sats[satNum];
    FILE *xp;
    xp = fopen("MystryTracking.txt", "w+");
    printf("UTC\t\t\tAZ\t\tEL\t\tAZ-vel\t\tEL-vel\t\tRange-Rate\t\tRange\t\tDoppler\t\tLevel\n");
    printf("\t\t\tdeg\t\tdeg\t\tdeg/sec\t\tdeg/sec\t\tkm\t\tkm/sec\t\t\tkHz\t\tdbm\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    fprintf(xp,"# UTC Date/Time   Azimuth and AZ_Velocity   Elevation and EL_Velocity\n");

    double currentTime;
    currentTime = JulianDateStart;
    int acquired=0;
    int lost = 0;

    FILE *stk;
    stk = fopen("selectedsat.e", "w+");
    fprintf(stk, "%s", "stk.v.11.0\n");
    fprintf(stk, "\nBEGIN Ephemeris\n");
    fprintf(stk,"\nNumberOfEphemerisPoints	%d\n", 30);
    char YR[5], MO[3], D[3], HR[3], MIN[3], S[3], *MONTH;
    double mon;
    char *EpochDat = jd2dat(JulianDateStart);
    strncpy(YR, EpochDat,4);YR[4] = '\0';
    strncpy(MO, EpochDat+5,2);MO[2] = '\0';
    strncpy(D, EpochDat+8,2);D[2] = '\0';
    strncpy(HR, EpochDat+11,2); HR[2] = '\0';
    strncpy(MIN, EpochDat+14,2);MIN[2] = '\0';
    strncpy(S, EpochDat+17,2);S[2] = '\0';
    mon = atof(MO);
    if(mon==1){MONTH = "Jan";}
    if(mon==2){MONTH = "Feb";}
    if(mon==3){MONTH = "Mar";}
    if(mon==4){MONTH = "Apr";}
    if(mon==5){MONTH = "May";}
    if(mon==6){MONTH = "Jun";}
    if(mon==7){MONTH = "Jul";}
    if(mon==8){MONTH = "Aug";}
    if(mon==9){MONTH = "Sep";}
    if(mon==10){MONTH = "Oct";}
    if(mon==11){MONTH = "Nov";}
    if(mon==12){MONTH = "Dec";}
    fprintf(stk, "\nScenarioEpoch	%s %s %s %s:%s:%s\n", D, MONTH, YR, HR, MIN, S);
    fprintf(stk,"\nInterpolationMethod            Lagrange\n" );
    fprintf(stk,"\nInterpolationOrder            7\n");
    fprintf(stk, "\nCentralBody            Earth\n");
    fprintf(stk,"\nCoordinateSystem            Fixed");
    fprintf(stk, "\n");fprintf(stk, "\n");fprintf(stk, "\n");
    fprintf(stk,"%s", "EphemerisTimePosVel\n\n");
    double timey = 0;
    for( ;currentTime<JulianDateStop; currentTime = currentTime+frcofd(0,0,step)){
	double mA, mM;
	double satEpoch = sat.refepoch;
	double mA0 = sat.meanan;
	double nMM = sat.meanmo;
	double ndMM = sat.ndot;
	double n2dMM = sat.nddot6;
	mean_anomaly_motion(&mA, &mM, currentTime, jdatep(satEpoch), mA0, nMM, ndMM, n2dMM);
	double mMrev=mM/(2*PI);

	double eccAnom = KeplerEqn(mA, sat.eccn);

	Vector *eciPos, *eciVel;
	eciPos = (Vector*)malloc(sizeof(Vector));
	eciVel = (Vector*)malloc(sizeof(Vector));

	double sMA = CUBE_ROOT(398600.4418/(4*PI*PI*mMrev*mMrev));
	sat_ECI(eciPos, eciVel, sat.eccn, eccAnom, sMA, sat.raan*PI/180,sat.argper*PI/180, sat.incl*PI/180, mM);
	Vector *ecfPos, *ecfVel;
	ecfPos = (Vector*)malloc(sizeof(Vector));
	ecfVel = (Vector*)malloc(sizeof(Vector));

	double thetat = THETAJ(currentTime, JulianDateStart);
	sat_ECF(ecfPos, ecfVel, thetat, eciPos, eciVel);
	Vector *stnPos, *rtPos, *rtVel;
	stnPos = (Vector*)malloc(sizeof(Vector));
	station_ECF(stnPos, stn->stnlong, stn->stnlat, stn->stnalt);
	rtPos = (Vector*)malloc(sizeof(Vector));
	rtVel = (Vector*)malloc(sizeof(Vector));
	range_ECF2topo(rtPos, rtVel, *stnPos, ecfPos, ecfVel, stn->stnlong, stn->stnlat);
	fprintf(stk,"%+.14e %+.14e %+.14e %+.14e %+.14e %+.14e %+.14e\n",
		timey, 1000*ecfPos->x, 1000*ecfPos->y,1000*ecfPos->z,
		1000*ecfVel->x, 1000*ecfVel->y, 1000*ecfVel->z);
	timey = timey +step;
	double az;
	double el;
	double azV;
	double elV;
	LookAngles *LA =(LookAngles*) malloc(sizeof(LookAngles));
	range_topo2look_angles(LA, az, el, azV, elV, rtPos, rtVel);
	//printf("rtPOS %f rtVel %f", rtPos, rtVel);

	double R, v, c;
	R=magntd(*rtPos);
	v=(rtVel->x*rtPos->x+rtVel->y*rtPos->y+rtVel->z*rtPos->z)/R;
	c=299792.458; //in km/s
	ss[num] = linkstrength(sqrt(rtPos->x*rtPos->x+rtPos->y*rtPos->y+rtPos->z*rtPos->z));
	fD[num]=(-v/c)*ss[num];

	printf("%s\t%f\t%f\t%f\t%f\t%f\t%f\t\t%f\t%f\n", jd2dat(currentTime),fixangdeg(LA->azimuth),fixangdeg(LA->elevation),LA->azimuth_velocity,LA->elevation_velocity,sqrt(rtPos->x*rtPos->x+rtPos->y*rtPos->y+rtPos->z*rtPos->z),sqrt(rtVel->x*rtVel->x+rtVel->y*rtVel->y+rtVel->z*rtVel->z), fD[num], linkstrength(sqrt(rtPos->x*rtPos->x+rtPos->y*rtPos->y+rtPos->z*rtPos->z)));

	double AZfix, ELfix;
	double AZms, AZmin, AZs, ELms,ELmin, ELs;
	double AZd, AZm, ELd, ELm;
	AZfix=fixangdeg(LA->azimuth);
	AZms=frac(AZfix);
	AZd=AZfix-AZms;
	AZmin=AZms*60;
	AZs=frac(AZmin);
	AZm=AZmin-AZs;

	ELfix=fixangdeg(LA->elevation);
	ELms=frac(ELfix);
	ELd=ELfix-ELms;
	ELmin=ELms*60;
	ELs=frac(ELmin);
	ELm=ELmin-ELs;

	double year, mon, day, hh, mm, se;
	double DOY;
	char YR[5], MO[3], D[3], HR[3], MIN[3], S[3];

	char *currentTimeChar, currentTimeCharArray[20];
	currentTimeChar = jd2dat(currentTime);
	strncpy(currentTimeCharArray, currentTimeChar,20);

	strncpy(YR, currentTimeCharArray,4);
	YR[4] = '\0';
	strncpy(MO, currentTimeCharArray+5,2);
	MO[2] = '\0';
	strncpy(D, currentTimeCharArray+8,2);
	D[2] = '\0';
	strncpy(HR, currentTimeCharArray+11,2);
	HR[2] = '\0';
	strncpy(MIN, currentTimeCharArray+14,2);
	MIN[2] = '\0';
	strncpy(S, currentTimeCharArray+17,2);
	S[2] = '\0';
	year = atof(YR);
	mon = atof(MO);
	day = atof(D);
	hh = atof(HR);
	mm = atof(MIN);
	se = atof(S);
	DOY = doy(year, mon, day);
	fprintf(xp,"%.0f.%03.0f.%02.0f:%02.0f:%02.0f %03.0f %02.0f %03.1f %03.1f %03.0f %02.0f %03.1f %03.1f\n", year, DOY, hh, mm, se, AZd, AZm, AZs, LA->azimuth_velocity, ELd, ELm, ELs, LA->elevation_velocity);

    }
    fclose(fp);
    fprintf(stk, "\nEphemeris finished\n");
    fclose(stk);
    return 0;
}

