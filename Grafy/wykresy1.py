import matplotlib.pyplot as plt

# Dane
densities = [0.25, 0.5, 0.75, 1]

# Czasy dla macierzy sąsiedztwa
times_matrix = [
    [3.06, 2.63, 3.02, 22.12],
    [4.86, 18.3, 19.2, 209.46],
    [32.24, 44.34, 71.96, 1446.92],
    [457.63, 608.96, 1362.12, 9894.44],
    [1236.8, 2249.01, 3054.96, 38294.6]
]

# Czasy dla listy sąsiedztwa
times_list = [
    [1.04, 4, 2.57, 21.24],
    [5.85, 10.57, 22.87, 258.89],
    [17.76, 35.78, 52.24, 762.46],
    [98.84, 198.62, 321.82, 11470.6],
    [186.99, 387.52, 665.41, 43610.9]
]

# Tworzenie wykresów dla macierzy sąsiedztwa
plt.figure(figsize=(12, 8))
for i in range(len(times_matrix)):
    plt.plot(densities, times_matrix[i], marker='o', label=f'{10 * (i+1)} wierzchołków')
plt.title('Czas wykonania dla macierzy sąsiedztwa')
plt.xlabel('Gęstość grafu')
plt.ylabel('Średni czas [us]')
plt.legend(title='Liczba wierzchołków')
plt.grid(True)
plt.show()

# Tworzenie wykresów dla listy sąsiedztwa
plt.figure(figsize=(12, 8))
for i in range(len(times_list)):
    plt.plot(densities, times_list[i], marker='o', label=f'{10 * (i+1)} wierzchołków')
plt.title('Czas wykonania dla listy sąsiedztwa')
plt.xlabel('Gęstość grafu')
plt.ylabel('Średni czas [us]')
plt.legend(title='Liczba wierzchołków')
plt.grid(True)
plt.show()
