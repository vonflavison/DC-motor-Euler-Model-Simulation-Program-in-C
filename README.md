# DC-motor-Euler-Model-Simulation-Program-in-C
This is a C program for simulating DC motor plant model. The program computes the model using Euler method.

REMARK:

1. To test this program, execute "run.exe"

2. Use the following TEST CASE
   
   A. MOTOR PARAMETERS 

      a). Ke = 0.1 [V/ms^-1]

      b). Kf = 0.2 [-]

      c). Kt = 0.1 [Nm/A]

      d). J = 0.02 [kgm^2]

      e). R = 2.0 [ohm]

      f). L = 0.5 [H]

  B. SYSTEM INPUT

     a). Vin = 1 [V]

  C. SIMULATION CONDITION

     a). Time = 3 [s]

![Output](https://user-images.githubusercontent.com/6802278/204088437-61a6eae1-d646-4773-a1f6-88a295857cde.png)

3. It is also posible to simulate any other DC motor and for longer duration and for higher input voltages. To do so,

     i. Go to "main.c" and edit the section "//PLOT THE RESULTS"

    ii. The limts of "xrange" and "yrange" have to be edited to suit the case study

   iii. After making the edits, recompile the program using "g++ orun main.c param.c plant.c function.c"
