def area(rectangle):
    [A,B] = rectangle
    return abs(B[0] - A[0]) * abs(B[1] - A[1])
def solve(points):
    if len(points)<=2:
        return 0
    points_x = sorted(points, key = lambda x: x[0])
    ymx = {}
    for p in points_x:
        if p[0] not in ymx:
            ymx[p[0]] = [p[1], p[1]]
            continue
        if p[1] < ymx[p[0]][0]:
            ymx[p[0]][0] = p[1]
        elif p[1] > ymx[p[0]][1]:
            ymx[p[0]][1] = p[1]
    
    y_right = {points_x[-1][0]: ymx[points_x[-1][0]]}
    for i in range(N-2,-1, -1):
        y_right[points_x[i][0]] = [min(y_right[points_x[i+1][0]][0], ymx[points_x[i][0]][0]),
                                    max(y_right[points_x[i+1][0]][1], ymx[points_x[i][0]][1])]
    r1_x = [points_x[0][0],points_x[0][0]]
    r2_x = [points_x[-1][0], points_x[-1][0]]
    r1_y = [ymx[points_x[0][0]][0],ymx[points_x[0][0]][1]]
    r2_y = [y_right[points_x[-1][0]][0],y_right[points_x[-1][0]][1]]
    area_max = float('inf')
    for i in range(N-1):
        r1_x[1] = points_x[i][0]
        r2_x[0] = points_x[i+1][0]
        if r1_y[0] > ymx[points_x[i][0]][0]:
            r1_y[0] = ymx[points_x[i][0]][0]
        if r1_y[1] < ymx[points_x[i][0]][1]:
            r1_y[1] = ymx[points_x[i][0]][1]
        r2_y = y_right[points_x[i+1][0]]
        new_area = area([[r1_x[0],r1_y[0]],[r1_x[1],r1_y[1]]]) + area([[r2_x[0],r2_y[0]],[r2_x[1],r2_y[1]]])
        if new_area < area_max:
            area_max = new_area
    points = [[y,x] for [x,y] in points]
    points_x = sorted(points, key = lambda x: x[0])
    ymx = {}
    for p in points_x:
        if p[0] not in ymx:
            ymx[p[0]] = [p[1], p[1]]
            continue
        if p[1] < ymx[p[0]][0]:
            ymx[p[0]][0] = p[1]
        elif p[1] > ymx[p[0]][1]:
            ymx[p[0]][1] = p[1]
    
    y_right = {points_x[-1][0]: ymx[points_x[-1][0]]}
    for i in range(N-2,-1, -1):
        y_right[points_x[i][0]] = [min(y_right[points_x[i+1][0]][0], ymx[points_x[i][0]][0]),
                                    max(y_right[points_x[i+1][0]][1], ymx[points_x[i][0]][1])]
    r1_x = [points_x[0][0],points_x[0][0]]
    r2_x = [points_x[-1][0], points_x[-1][0]]
    r1_y = [ymx[points_x[0][0]][0],ymx[points_x[0][0]][1]]
    r2_y = [y_right[points_x[-1][0]][0],y_right[points_x[-1][0]][1]]
    full_rect = [[points_x[0][0], y_right[points[0][0]][0]], [points_x[-1][0],y_right[points[0][0]][1]]]
    for i in range(N-1):
        r1_x[1] = points_x[i][0]
        r2_x[0] = points_x[i+1][0]
        if r1_y[0] > ymx[points_x[i][0]][0]:
            r1_y[0] = ymx[points_x[i][0]][0]
        if r1_y[1] < ymx[points_x[i][0]][1]:
            r1_y[1] = ymx[points_x[i][0]][1]
        r2_y = y_right[points_x[i+1][0]]
        new_area = area([[r1_x[0],r1_y[0]],[r1_x[1],r1_y[1]]]) + area([[r2_x[0],r2_y[0]],[r2_x[1],r2_y[1]]])
        if new_area < area_max:
            area_max = new_area
    return area_max
for _ in range(int(input())):
    N = int(input())
    points = [[int(x) for x in input().split()] for i in range(N)]
    print(solve(points))
