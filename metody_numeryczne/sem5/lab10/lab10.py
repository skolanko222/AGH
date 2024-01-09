import numpy as np
import matplotlib.pyplot as plt
def main():
    a = [0.0,0.0,0.0]
    b = [0.0,0.1,1.0]
    fig, ax = plt.subplots(figsize=(10, 4))
    for i in range(3):
        E = np.loadtxt('data/map_alpha_{0}_beta_{1}.txt'.format(a[i], b[i]))
        t = np.linspace(0, 50, len(E))
        if ax is None:
            ax = plt.gca()
        ax.plot(t, E, label='alpha={0} beta={1}'.format(a[i], b[i]))
        ax.set_xlabel('t')
        ax.set_ylabel('E')
        plt.xticks(np.arange(0, 51, 5))
        ax.set_title('E(t)')
        ax.legend()

    ax.figure.savefig('plot/E(t).png')
    plt.clf()
    for i in range(len(b)):
        u = np.loadtxt('data/E(t)_alpha_{0}_beta_{1}.txt'.format(a[i], b[i])).T
        x = np.linspace(0, 16, u.shape[1])
        t = np.linspace(0, 50, u.shape[0])
        plt.figure(figsize=(10, 5))
        plt.imshow(u, cmap='gnuplot', extent=[t[0], t[-1], x[0], x[-1]])
        plt.colorbar()
        plt.xlabel('t')
        plt.ylabel('x')
        plt.xticks(np.arange(0, 51, 5))
        plt.title('alpha={0} beta={1}'.format(a[i], b[i]))
        plt.savefig('plot/map{0}_beta{1}.png'.format(a[i],b[i]))

if __name__ == '__main__':
    main()