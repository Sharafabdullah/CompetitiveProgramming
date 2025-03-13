def getColor(x, y, step):
    if step == 1:
        return 1  # red
    
    prevSize = getSize(step - 1)
    currentSize = getSize(step)
    
    # Check if point is in top triangle
    if x <= prevSize:
        return getColor(x, y, step - 1)
    
    # Check if point is in inverted blue triangle
    if isInMiddleTriangle(x, y, prevSize, currentSize):
        return 0  # blue
    
    # Must be in one of the side triangles
    # Adjust coordinates and recurse
    newCoords = adjustCoordinates(x, y, prevSize)
    return getColor(newCoords.x, newCoords.y, step - 1)
