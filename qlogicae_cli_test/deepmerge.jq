def deepmerge(a; b):
  if (a | type) == "object" and (b | type) == "object" then
    reduce (b | keys_unsorted[]) as $k (a;
      .[$k] = if .[$k] == null then b[$k]
              else deepmerge(.[$k]; b[$k])
              end)
  elif (a | type) == "array" and (b | type) == "array" then
    a + b
  elif (a | type) == (b | type) then
    [a, b]
  else
    b
  end;

reduce .[] as $item ({}; deepmerge(.; $item))
