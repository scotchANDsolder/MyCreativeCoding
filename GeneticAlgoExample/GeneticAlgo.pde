
// Mutation rate
float mutationRate;
// Population total
int totalPopulation = 1000;
float maxFit = 0;
int bestDNA;

// Population array
DNA[] population;
// Mating pool ArrayList
ArrayList<DNA> matingPool;
// Target phrase
String target;

void setup() {
  size(640, 360);

  // Initializing target phrase and mutation rate
  target = "abhishek narula";
  mutationRate = 0.01;

  // <b><span style="font-size: 110%; text-decoration:underline;">Step 1: Initialize Population</b></span>
  population = new DNA[totalPopulation];
  for (int i = 0; i < population.length; i++) {
    population[i] = new DNA();
  }
}

void draw() {


  // Step 2a: Calculate fitness.
  for (int i = 0; i < population.length; i++) {
    population[i].fitness();
//println(population[i].fitness);
  }

  // Step 2b: Build mating pool.
  ArrayList<DNA> matingPool = new ArrayList<DNA>();

  for (int i = 0; i < population.length; i++) {
    //[full] Add each member n times according to its fitness score.
    int n = int(population[i].fitness * 100);
    for (int j = 0; j < n; j++) {
      matingPool.add(population[i]);
    }
    //[end]
  }

  for (int i = 0; i < population.length; i++) {
    int a = int(random(matingPool.size()));
    int b = int(random(matingPool.size()));
    DNA partnerA = matingPool.get(a);
    DNA partnerB = matingPool.get(b);
    //println(partnerA.fitness);
    // Step 3a: Crossover
    DNA child = partnerA.crossover(partnerB);
    child.fitness();
    
    // Step 3b: Mutation
    child.mutate(mutationRate);

    // Note that we are overwriting the population with the new
    // children.  When draw() loops, we will perform all the same
    // steps with the new population of children.
    population[i] = child;
    
  }
  
  for (int i = 0; i < population.length; i++) {
    if( population[i].fitness > maxFit){
      maxFit = population[i].fitness;
      bestDNA = i;
    
  }
  
  println("Best phrase:" + population[bestDNA].getPhrase());
  println("Best fintess:" + maxFit);
  }
  
  
  
}
