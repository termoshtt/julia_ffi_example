a = ones(Float32, 3, 3)
ccall((:make_twice_ptr, "myffi"), Cvoid, (Int32, Ptr{Float32}), 3*3, a)
print(a)
