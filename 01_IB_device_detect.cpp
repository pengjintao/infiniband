#include <iostream>
#include <mpi.h>
#include <infiniband/verbs.h>

using namespace std;
int main(int argc,char **argv)
{
    MPI_Init(&argc,&argv);

    MPI_Finalize();
}
