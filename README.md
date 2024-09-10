# basics
This tutorial teaches you how to build and run your labs in CE 4SP4:



### Logging in to the Teach Cluster
* More info about the (Teach Clsuter)[https://docs.scinet.utoronto.ca/index.php/Teach]
* What is compute node? what is login node?
* ssh to the teach cluster using ```ssh <username>@teach.scinet.utoronto.ca```
* `username` and password are already provided to you. Please do not share it with anyone
* What is `home` directory? What is `scratch` directory?
* Use `cd $SCRATCH` to go to the scratch directory
* Use `scp`to copy files from your local machine to the teach cluster and vice versa.



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


### What is Google Benchmark?
* Google Benchmark is a C++ library to benchmark code. See more info [here](https://github.com/google/benchmark/blob/main/docs/user_guide.md)
* How do you read google benchmark output?
* How can I parse CSV? Python?
* Find the list of supported counter using `perf list`. See more info [here](https://github.com/google/benchmark/blob/main/docs/perf_counters.md)


### Local setup
* Pick your editor. 
* We show you how to use CLion to setup the code.