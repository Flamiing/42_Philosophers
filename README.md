# <p align="center">💭PHILOSOPHERS💭</p>

### <p align="center">Threads in Unix</p> ###

---
## What is this project about? </br>
**Philosophers** is a command line program written in **C** which is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat spaghetti without dying from hunger.</br></br>
To better understand the problem, I suggest reading this Wikipedia article about it -> [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

---
## Biggest Challenges 💪 ##

One of the biggest challenges I faced while working on the philosopher's problem was timing the threads correctly to prevent them from dying unexpectedly. I also had to deal with the `usleep` function, which can cause delays. To overcome this, I created a more precise function that allowed the threads to execute without any unexpected delays. Additionally, I faced the challenge of making sure that the philosophers didn't pick up the forks at the same time, as there was only one fork per philosopher and they needed two forks to eat. To solve this problem, I timed the process of picking up and leaving the forks correctly so that each philosopher could use them as required.

## How to use? ##

```bash
# Clone the repository:
git clone git@github.com:Flamiing/42_Philosophers.git

# Access the folder:
cd 42_Philosophers/philo/

# Compile the program:
make

# To run the program:
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat(optional)
```

## Examples:

- One must die:
  ```bash
  ./philo 1 800 200 200
  ```

- Nobody dies:
  ```bash
  ./philo 5 800 200 200
  ```

- Nobody dies and they eat minimum 7 times:
  ```bash
  ./philo 5 800 200 200 7
  ```

- Nobody dies:
  ```bash
  ./philo 4 410 200 200
  ```

- One must die:
  ```bash
  ./philo 4 310 200 100
  ```

- Nobody dies:
  ```bash
  ./philo 3 310 103 103
  ```

- One must die:
  ```bash
  ./philo 3 310 104 104
  ```
