Be aware that the coordinate inputs are given in order. 

Loop from the first coordinate to the next coordinates, putting the distanced walked into the "dist" vector.

Then, calculate the distance, which is the minimum of:
abs(dist[x2][y2]-dist[x2][y2])
loop distance - dist[x2][y2] + dist[x1][y1]
loop distance - dist[x1][y1] + dist[x2][y2]
