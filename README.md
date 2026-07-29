# Subin Lee (lee505) assignment for CE 4SP4
HW0

### Q&A
 At the very top of the README, add a clear title and answer the following questions (one brief paragraph per question):
How did you implement the linked list? (no plot is needed)
Insertion sort.

How long does it take to sort the list across different input sizes? (Include a plot supporting this data).


How did you optimize your code? How much faster is the improved version, and why? (Include a plot supporting this data).



### Assumptions
* The course said it "cannot provide remote server access for this assignment" so I have remade the build.sh to a MacOS/Linux environment 
* Build assumes the dependencies are already installed (i.e. cmake, gcc, python3)



### Cloning and Buidling the repository
* Use `git clone https://github.com/cheshmi/basics.git` to clone the repository in your scratch directory
* What is `git`?
* Use `cd basics` to go to the directory
* You first need to build the code using `bash build.sh`.
* What does the `build.sh` do? What us CMake?
* What is the profiling flag in the `build.sh` script?


### Running the code
* Use `sbatch run_teach_cluster.sh` to run the code on a compute nod of the teach cluster
* What is the difference between `sbatch` and `bash`?
* You should never run the code on the login node (unless it takes less than 30 seconds). Why?
* What is the output of the code?
* What does 'run_teach_cluster.sh' do?
* You can check the status of of your job using `squeue -u <username>`. What is the output of this command?
