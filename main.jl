
# native pointer interface
a = ones(Float32, 2, 3)
ccall((:make_twice_ptr, "myffi"), Cvoid, (Int32, Ptr{Float32}), 2*3, a)
println(a)

# jl_value_t* interface
b = ones(Float32, 2, 3)
ccall((:make_twice_array, "myffi"), Cvoid, (Any,), b)
println(b)
