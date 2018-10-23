#include <iostream>
#include <mpi.h>
#include <infiniband/verbs.h>

using namespace std;
int main(int argc,char **argv)
{
    MPI_Init(&argc,&argv);

    int rank,size;
    struct ibv_device ** IPH_Ib_devlist;
    struct ibv_device * Iph_dev;

    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    IPH_Ib_devlist = ibv_get_device_list(0);
    Iph_dev=IPH_Ib_devlist[0];

    if(rank == 0)
    {
    	cout<<Iph_dev->node_type<<endl;
    	cout<<Iph_dev->transport_type <<endl;
    	cout<<ibv_get_device_name(Iph_dev)<<endl;
    }


    ibv_free_device_list(IPH_Ib_devlist); 
    MPI_Finalize();
}
