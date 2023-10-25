import numpy as np
import matplotlib.pyplot as plt

# Define constants
epsilon = 1
delta = 0.1
nx = 150
ny = 100
V1 = 10
V2 = 0
xmax = delta * nx
ymax = delta * ny
sigma_x = 0.1 * xmax
sigma_y = 0.1 * ymax
omega_G = [0.6, 1.0]
omega_L = [1.0, 1.4, 1.8, 1.9]
TOL = 1e-8

# Define functions - jest tak jak w poleceniu
def calculate_S(V, rho,S=0):
    for i in range(0, nx-1):
        for j in range(0, ny-1):
            S += (delta**2) * (0.5*(((V[i+1,j]-V[i,j])/delta)**2) + 0.5*(((V[i,j+1]-V[i,j])/delta)**2) - (rho[i,j]*V[i,j]))
    return S
#  - jest tak jak w poleceniu
def global_relaxation(V, rho, omega):
    V_new = np.zeros_like(V)
    V_new[:, 0] = V1
    V_new[:, ny] = V2
    for i in range(1, nx-1):
        for j in range(1, ny-1):
            V_new[i, j] = 0.25 * (V[i+1, j] + V[i-1, j] + V[i, j+1] + V[i, j-1] + (delta**2/epsilon) * rho[i, j])
    for j in range (1, ny-1):
        V[0, j] = V[1, j]
        V[nx, j] = V[nx-1, j]
    V = (1 - omega) * V + omega * V_new
    return V
#  - jest tak jak w poleceniu
def local_relaxation(V, rho, omega):
    for i in range(1, nx-1):
        for j in range(1, ny-1):
            V[i, j] = (1 - omega) * V[i, j] + (omega/4) * (V[i+1, j] + V[i-1, j] + V[i, j+1] + V[i, j-1] + (delta**2/epsilon) * rho[i, j])
    for j in range (1, ny-1):
        V[0, j] = V[1, j]
        V[nx, j] = V[nx-1, j]
    return V

# Define density function - jest tak jak w poleceniu
def rho(x, y):
    rho1 = np.exp(-((x - 0.35 * xmax)**2 / sigma_x**2 + (y - 0.5 * ymax)**2 / sigma_y**2))
    rho2 =-np.exp(-((x - 0.65 * xmax)**2 / sigma_x**2 + (y - 0.5 * ymax)**2 / sigma_y**2))
    return rho1 + rho2

# Initialize potential and density arrays
V = np.zeros((nx+1, ny+1))
V_06 = np.zeros((nx+1, ny+1))
V_10 = np.zeros((nx+1, ny+1))
V_06[:, 0] = V1
V_06[:, ny] = V2
V_10[:, 0] = V1
V_10[:, ny] = V2
rho_array = np.zeros((nx+1, ny+1))
for i in range(nx+1):
    for j in range(ny+1):
        rho_array[i, j] = rho(i*delta, j*delta)


fig, (ax1, ax2) = plt.subplots(1, 2)

# Solve Poisson equation using global relaxation method
omega = 0.6
S_list = []
S = calculate_S(V_06, rho_array)
S_list.append(S)
it = 0
while True:
    V_06 = global_relaxation(V_06, rho_array, omega)
    it += 1
    S_new = calculate_S(V_06, rho_array)
    S_list.append(S_new)
    check = abs((S_new - S)/S)
    print(TOL, "\t>\t", check, "\t", S, "\t", it)
    if check < TOL:
        print(f'omega_G={omega}, it={it}')
        break
    S = S_new
ax1.plot(S_list, label=f'omega_G={omega}, it={it}')

omega = 1.0
S_list = []
S = calculate_S(V_10, rho_array)
S_list.append(S)
it = 0
while True:
    V_10 = global_relaxation(V_10, rho_array, omega)
    it += 1
    S_new = calculate_S(V_10, rho_array)
    S_list.append(S_new)
    check = abs((S_new - S)/S)
    print(TOL, "\t>\t", check, "\t", S, "\t", it)
    if check < TOL:
        print(f'omega_G={omega}, it={it}')
        break
    S = S_new
ax1.plot(S_list, label=f'omega_G={omega}, it={it}')


# Solve Poisson equation using local relaxation method
for omega in omega_L:
    V = np.zeros((nx+1, ny+1))
    V[:, 0] = V1
    V[:, ny] = V2
    S_list = []
    S = calculate_S(V, rho_array)
    S_list.append(S)
    it = 0
    while True:
        V = local_relaxation(V, rho_array, omega)
        it += 1
        S_new = calculate_S(V, rho_array)
        S_list.append(S_new)
        check = abs((S_new - S)/S)
        print(TOL, "\t>\t", check, "\t", S, "\t", it)
        if check < TOL:
            print(f'omega_L={omega}, it={it}')
            break
        S = S_new
    ax2.plot(S_list, label=f'omega_L={omega}, it={it}')

ax1.set_title('Global relaxation method')
ax1.set_xlabel('Iteration')
ax1.set_ylabel('S')
ax1.set_xticks([1,10, 100, 1000, 10000, 100000])
ax1.set_xscale('log')
ax1.legend()
ax2.set_title('Local relaxation method')
ax2.set_xlabel('Iteration')
ax2.set_ylabel('S')
ax2.set_xticks([1,10, 100, 1000, 10000, 100000])
ax2.set_xscale('log')
ax2.legend()
plt.show()

def laplacian(V):
    # Compute Laplacian using finite differences
    laplacian_V = np.zeros_like(V)
    laplacian_V[1:-1, 1:-1] = (V[1:-1, :-2] + V[1:-1, 2:] + V[:-2, 1:-1] + V[2:, 1:-1] - 4*V[1:-1, 1:-1])
    
    return laplacian_V

# Plot solution error
# plt.imshow(delta, cmap='coolwarm', origin='lower', extent=[0, xmax, 0, ymax])
# plt.colorbar()
# plt.xlabel('x')
# plt.ylabel('y')
# plt.title('Solution Error')
# plt.show()

delta06 = np.zeros((nx+1, ny+1))
delta10 = np.zeros((nx+1, ny+1))
for i in range(nx+1):
    for j in range(ny+1):
        delta06[i, j] = laplacian(V_06)[i, j] - rho_array[i, j]/epsilon
        delta10[i, j] = laplacian(V_10)[i, j] - rho_array[i, j]/epsilon

plt.imshow(delta06, cmap='seismic', origin='lower', extent=[0, xmax, 0, ymax])
plt.colorbar(label='Error')
plt.clim(vmin=np.min(delta06), vmax=np.max(delta06))
plt.title('Solution Error w=0.6')
plt.xlabel('x')
plt.ylabel('y')
plt.show()

plt.imshow(delta10, cmap='seismic', origin='lower', extent=[0, xmax, 0, ymax])
plt.colorbar(label='Error')
plt.clim(vmin=np.min(delta10), vmax=np.max(delta10))
plt.xlabel('x')
plt.ylabel('y')
plt.title('Solution Error w=1.0')
plt.show()