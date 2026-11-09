const users = [
  { firstName: "Alex", age: 22, isWoman: false },
  { firstName: "Maria", age: 19, isWoman: true },
  { firstName: "Daniel", age: 25, isWoman: false },
  { firstName: "Anna", age: 21, isWoman: true },
  { firstName: "Michael", age: 30, isWoman: false },
  { firstName: "Sofia", age: 18, isWoman: true },
];

export default function User() {
  return (
    <>
      {users.map((us) => (
        <div key={us.firstName}>
          {us.firstName} — {us.age} — {us.isWoman ? "Woman" : "Man"}
        </div>
      ))}
    </>
  );
}
