/*
 * Vector.h
 *
 *  Created on: Mar 17, 2017
 *      Author: mikelefakadu
 */

#ifndef vec
#define vec

typedef struct Vector {
	double x;
	double y;
	double z;
	double mag;
} Vector;

#endif


#ifndef VECTOR_H_
#define VECTOR_H_

double myangle(Vector *v1, Vector *v2);

double magntd(struct Vector VECTR);

int mycross(Vector *v3, Vector *v1, Vector *v2);

int vecadd(Vector *v3, Vector *v1, Vector *v2);

int station_ECF(Vector *stn_ECF_pos, double station_longitude, double station_latitude, double station_elevation);

#endif /* VECTOR_H_ */
