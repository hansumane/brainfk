[ multiply.bf -- multiplies two bytes.
  Takes first two bytes from the input,
  multiplies them, stores the result in
  the first cell and outputs the value. ]

,>,<
[>[>+>+<<-]>[<+>-]<<-]
>>>[<<<+>>>-]<<[-]<.
