#include "plant.h"

double *f1;
double Yn1[3] = {0.0,0.0,0.0};

//Function for computing dx(t)/dt = Ax(t) + Bu(t)
double *DiffEquation(struct PlantParams plant, double *Variable, double InputVolt){
    double K_e = plant.Ke, K_f = plant.Kf, K_t = plant.Kt, mJ = plant.J, mR = plant.R, mL = plant.L;
    
    double A[3][3] = {
        {0.0, 1.0, 0.0},
        {0.0, -(K_f/mJ), (K_t/mJ)},
        {0.0, -(K_e/mL), -(mR/mL)}
    };
    double B[3] = {0.0, 0.0, (1/mL)};
    double u = InputVolt; //i.e., u(t)

    double *X = Variable; //i.e. x(t) = {Theta(t), omega(t), i(t)}
    static double dX[3]; //This array contains the result dx(t)/dt

    //comput model dx(t)/dt = Ax(t) + Bu(t)
    for (int i = 0; i < 3; i++)
    {
        dX[i] = 0.0;
        for (int j = 0; j < 3; j++)
        {
            dX[i] += A[i][j]*X[j];
        }
        dX[i] += B[i]*u;  
    }
    
    return dX;
}

//This function computes the Euler Model Yn+1 = Yn + H*f1
double *EulerModel(struct PlantParams plant, double InputVolt){
    //Differential equations y = dx(t)/dt
    f1 = DiffEquation(plant, Yn1, InputVolt); //i.e., f1 = f(Yn1, tn)

    for (int k = 0; k < 3; k++)
    {
        //Euler method: The solution, y, of a differential equation f = dy(t)/dt is given by:
		//Yn+1 = Yn + H*f1 
        Yn1[k] += TS*f1[k]; 
    }
    
    return Yn1;
}
