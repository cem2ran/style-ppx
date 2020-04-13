open Printf;

module Person = {
  let make = (~name, ~age, ()) =>
    printf("Hi %s! You are %d years old.\n", name, age);
};

/* Use object literal notation to call `Person.make`. */
Person({"name": "Dylan", "age": 32});