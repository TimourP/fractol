

def make_gradient(color1, color2, n, show_last = False):
	red_step = (color2[0] - color1[0]) / (n-1)
	green_step = (color2[1] - color1[1]) / (n-1)
	blue_step = (color2[2] - color1[2]) / (n-1)

	gradient_list = []

	for i in range(n if show_last else n - 1): 
		red = int(color1[0] + (red_step * i))
		green = int(color1[1] + (green_step * i))
		blue = int(color1[2] + (blue_step * i))
		gradient_list.append((red, green, blue))

	return gradient_list

colors = [(63, 81, 181), (3, 169, 244), (0, 188, 212), (205, 220, 57), (255, 152, 0), (244, 67, 54)]

count = 0

for color in range(len(colors) - 1):
	gradiant = make_gradient(colors[color], colors[color + 1], 30, True if color == len(colors) - 2 else False)
	
	for gr in gradiant:
		count += 1
		print(f"std::make_tuple{gr},")

print(count)