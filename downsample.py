import numpy as np

def downsample(x, h=2, v=2):
    '''Downsampling with averaging'''
    avg_h = lambda m: np.mean(m.reshape(-1, h), 1)
    x_ds = np.apply_along_axis(avg_h, 1, x)
    avg_v = lambda m: np.mean(m.reshape(-1, v), 1)
    return np.apply_along_axis(avg_v, 0, x_ds)

def upsample(x, h=2, v=2):
    '''Nearest Neighbour interpolation'''
    return np.repeat(np.repeat(x, h, 1), v, 0)