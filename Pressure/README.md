
# Pressure
*Calculating barometric pressure using a simple equation*

## Introduction
This project was one of the first I did for my Computer Science degree. This was for CSE1001 - Fundamentals of Software Development. The program was pretty simple, and I already had some experience coding when I took AP CSP in high school. However, it's still pretty clear there's room for improvement. 

## Background
**Barometric pressure** or just **air pressure**, is a measurement of force caused by the weight of air and water particles in the atmosphere. There are a couple of different ways to measure air pressure, but a common formula to calculate can be found as follows:
```math
P = P_{b}[1-\frac{L_{M, b}}{T_{M, b}}h-h_{b}]^\frac{g^{'}_{0}M_{0}}{{R*L}_{M,b}}
```

where:
* $$P_{b}$$ is the reference pressure
* $$T_{M, b}$$ is the reference temperature
* $$L_{M, b}$$ is the temperature lapse rate
* $$h$$ is the height where pressure is calculated
* $$h_{b}$$ is the reference height
* $$R^{*}$$ is the universal gas constant
* $$g_{0}$$ is gravitational acceleration
* $$M$$ is the molar mass of Earth's air

This equation can be used to calculate the pressure at any given height with reference. However, the simplest application of this formula is to find the pressure at a given height with reference to pressure directly on Earth's surface. 

This first project makes that assumption to give the average newbie programmer a chance to understand how variables and mathematical functions work within programs. 

## Approach
### Basic Improvements
One of the first things I noticed in my old program was that I calculated pressure in a very resource-inefficient way. Namely, there is only one dependent variable in our program and our frame of reference for the program never changes. This means we can calculate most of the equation before runtime and save recalculating the same values over and over. 

Similarly, most of these variables don't change during runtime, so I can change them to global constants and pull them when needed. However, this touches on the first new issue we need to tackle. 

### Avoiding Loss of Significance
What gets hidden in this program is the fact we're performing a scientific calculation. If this program were to be used practically, then manintaining proper significance is vital to getting an accurate result. 

To make our calculations more accurate, we can rewrite some of our formula to avoid dividing by very small amounts. This can be seen with the power term used in the equation. Thus, we can rewrite the calculation as multiplying by the inverse of the denominator. 

### Adding More Functionality
Creating the new program is easy enough, but we could add some additional functionality to make the program a bit more practical for an actual user. 

Let's assume the person using this program may want to calculate the program in a batch mode. We'll say for the sake of simplicity that the user submits either a list of altitudes that want to use for calculation or a file that contains that list. 

We can add some CLI functionality for our program by adding flag handling. In this case, the program will have 3 flags:

* -i will trigger a prompt for altitude from stdin, and output the result. If the program is called without parameters, then this is the default behavior.
* -l will specify a list of altitudes the user will provide via the command line. 
* -b will specifiy a file (.csv for this project) that contains the list that the program will pull from. 

We should add a -h flag to print usage information for anyone who wants to know how to utilize our program. 
