

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"



#include "Data/SpDataAccessMode.hpp"
#include "Utils/SpUtils.hpp"
#include "Random/SpPhiloxGenerator.hpp"


#include "mcglobal.hpp"



#include "Data/SpDataAccessMode.hpp"
#include "Utils/SpUtils.hpp"

#include "Task/SpTask.hpp"
#include "Legacy/SpRuntime.hpp"
#include "Utils/SpTimer.hpp"
#include "Utils/small_vector.hpp"
#include "Utils/SpBufferDataView.hpp"
#include "Utils/SpArrayView.hpp"
#include "Utils/SpHeapBuffer.hpp"


#include "UTester.hpp"
#include "utestUtils.hpp"



#include <algorithm>
#include <iostream>
#include <vector>
#include <string>



using namespace std;

template <typename C> void print(const string& s, const C& c) {
    cout << s;
    for (const auto& e : c) { cout << e << " "; }
    cout << endl;
}

void fillVector(vector<int>& v)
{
    // A local static variable.
    static int nextValue = 1;

    // The lambda expression that appears in the following call to
    // the generate function modifies and uses the local static
    // variable nextValue.
    generate(v.begin(), v.end(), [] { return nextValue++; });
    //WARNING: this isn't thread-safe and is shown for illustration only
}


int gen()
{
    static int i = 0;
    return ++i;
}

class MyFunction001
{
public:
    // The required constructor for this example.
    explicit MyFunction001(int& evenCount)
        : m_evenCount(evenCount) { }

    // The function-call operator prints whether the number is
    // even or odd. If the number is even, this method updates
    // the counter.
    void operator()(int n) const {
        cout << n;

        if (n % 2 == 0) {
            cout << " is even " << endl;
            ++m_evenCount;
        } else {
            cout << " is odd " << endl;
        }
    }

private:
    // Default assignment operator to silence warning C4512.
    MyFunction001& operator=(const MyFunction001&);

    int& m_evenCount; // the number of even variables in the vector.
};




int main(int argc, char **argv)
{

    int NumThreads = SpUtils::DefaultNumThreads();
    int NbThreads = 2;


    if (1==1)
    {

        NbThreads = 5;

        SpRuntime runtime(NbThreads);
        std::cout<<"Nb Thread="<<runtime.getNbThreads()<<"\n";
        std::cout<<"Nb CPU Workers="<<runtime.getNbCpuWorkers()<<"\n";
        int Num=runtime.getNbThreads();
        std::atomic<int> initVal(0);

            for(int idxThread = 0 ; idxThread < Num ; ++idxThread){
                runtime.task(SpParallelWrite(initVal),
                             [&](std::atomic<int>& initValParam){
                    
                    initValParam += 1;
                    
                    //cout<<initValParam<<" "<<Num<<"\n";
                    while(initValParam != Num){
                        //cout<<"NOT OK"<<"\n";
                        cout<<initValParam<<" ";
                        usleep(10000);
                        //cout<<initValParam<<" "<<Num<<"--";
                        
                    }
                    
                    
                        usleep(10);
                    
                });
            }

            runtime.waitAllTasks();
            runtime.generateDot("Runtime20.dot",true);
            runtime.generateTrace("Runtime20.svg");

            cout<<"\n";
    }//1==1


       

    NbThreads = 10;
    if (1==1)
    {
            SpRuntime runtime(NbThreads);
            std::cout<<"Nb Thread="<<runtime.getNbThreads()<<"\n";
            std::cout<<"Nb CPU Workers="<<runtime.getNbCpuWorkers()<<"\n";

            std::promise<long int> promises[10];

            int dumbVal = 0;

            for(int idxThread = 0 ; idxThread < runtime.getNbThreads() ; ++idxThread){
                runtime.task(SpParallelWrite(dumbVal),
                             [&,idxThread](int&){

                    //usleep(10);
                    promises[idxThread].set_value(idxThread);
                    const long int res = promises[(idxThread+1)%10].get_future().get();
                    //UASSERTETRUE(res == (idxThread+1)%10);
                    
                });
            }

            runtime.waitAllTasks();

            runtime.generateDot("Runtime22.dot",true);
            runtime.generateTrace("Runtime22.svg");
    }//End 1==1
    
}



