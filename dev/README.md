debouncing procedure

left = true, right = false ->
move foward

  left = true, right = true
  stop

  left = false, right = false
  flag

  left = false, right = true
  flag

left = false, right = true ->
move

  left = true, right = true
  stop

  left = false, right = false
  flag

  left = true, right = false
  flag

left = true, right = true
stop

left = false, right = false
move

