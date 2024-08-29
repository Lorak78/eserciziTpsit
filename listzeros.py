l = [0, 1, 2, 2, 0, 4, 0, 3, 0]
final_list = []
n_zeros = 0
for num in l:
    if num != 0:
        final_list.append(num)
    else:
        n_zeros += 1
final_list.extend([0] *n_zeros)
print(final_list)

#final_list.extend([0] * n_zeros)