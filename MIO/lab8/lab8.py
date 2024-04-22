class Solution2:
    def __init__(self, randomize_genes = False, mutation_chance = 0.5):
        self.genes = [0] * 16
        if randomize_genes:
            for i in range(8):
                if random.random() < mutation_chance:
                    self.genes[i] = 0
                else:
                    self.genes[i] = 1

  # funkcja przystosowania:
    def get_adaptation_binary(self):
        number = int("".join(str(x) for x in self.genes), 2) / 2.**16 # sprytny sposób na konwersję wektora bitów do liczby całkowitej w jednej linijce
        return math.sin(100*number + 0.1) + math.pow(number, -1.*number) + 0.2

    def get_adaptation_grey(self):
        n = int("".join(str(x) for x in self.genes), 2) # convert to int
        n ^= (n >> 1)
    
        # bin(n) returns n's binary representation with a '0b' prefixed
        # the slice operation is to remove the prefix
        return bin(n)[2:]

  # krzyżowanie jednopunktowe z innym osobnikiem:
    def crossover(self, other_solution):
        cut_position = random.randint(0,15)
        new_solution = Solution2()
        new_solution.genes[0:cut_position] = self.genes[0:cut_position]
        new_solution.genes[cut_position:] = other_solution.genes[cut_position:]
        return new_solution

  # mutacja przez obrót bitu na losowej pozycji:
    def mutation(self):
        mutation_position = random.randint(0,15)
        if self.genes[mutation_position] == 1:
            self.genes[mutation_position] = 0
        else:
            self.genes[mutation_position] = 1

sol = Solution2(randomize_genes = True)
print(sol.get_adaptation_binary()," ",sol.get_adaptation_grey())