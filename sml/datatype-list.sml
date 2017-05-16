datatype 'a List = Nil | Cons of 'a * 'a List;

fun concat(x: 'a List, y: 'a List): 'a List = 
    case x of
        Nil => y
      | Cons(h,t) => Cons(h, concat(t, y))

fun reverse(x: 'a List): 'a List = 
    case x of
        Nil => Nil
      | Cons(h,t) => concat(reverse t, Cons(h,Nil));

(*Test cases*)
val a = concat(Cons("m", Nil), Cons("7", Nil));
val it = reverse(a);
