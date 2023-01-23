// MainApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <casadi/casadi.hpp>

using namespace casadi;
using namespace std;

/**
Solve the Rosenbrock problem, formulated as the NLP:

minimize     x^2 + 100*z^2
subject to   z+(1-x)^2-y == 0

Joel Andersson, 2015-2016
*/

int main() {

    // Declare variables
    SX x = SX::sym("x");
    SX y = SX::sym("y");
    SX z = SX::sym("z");

    // Formulate the NLP
    SX f = pow(x, 2) + 100 * pow(z, 2);
    SX g = z + pow(1 - x, 2) - y;
    SXDict nlp = { {"x", SX::vertcat({x,y,z})},
                  {"f", f},
                  {"g", g} };

    // Create an NLP solver
    Function solver = nlpsol("solver", "ipopt", nlp);

    // Solve the Rosenbrock problem
    DMDict arg;
    arg["x0"] = vector<double>{ 2.5,3.0,0.75 };
    arg["lbg"] = arg["ubg"] = 0;
    DMDict res = solver(arg);

    //  Print solution
    cout << "Optimal cost:                     " << double(res.at("f")) << endl;
    cout << "Primal solution:                  " << vector<double>(res.at("x")) << endl;
    cout << "Dual solution (simple bounds):    " << vector<double>(res.at("lam_x")) << endl;
    cout << "Dual solution (nonlinear bounds): " << vector<double>(res.at("lam_g")) << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
