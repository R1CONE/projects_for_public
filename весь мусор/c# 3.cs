Public - ?????


Protracted - ?????? ? ?????? ??? ?? ? ??? ????????????




internal class Program
{
    static void Main(string[] args)
    {


        Robot bot = new Robot();


        bot.setValues("Bot", 12, new byte[] { 0, 0, 0 });
        bot.printValues();
        
    }
}


namespace projekt
{
    internal class Robot
    {
        public int weight;


        public string name;


        public byte[] cootdinates;


public Robot() {
            Console.WriteLine("Object has been created");
        }




        public void setValues(string _name, int _weight, byte[] _cootdinates)
        {
            name = _name;


            weight = _weight;


            cootdinates = _cootdinates;
        }


        public void printValues ()
        {
            Console.WriteLine("Name: " + name + "Weight: " + weight);


            foreach (var el in cootdinates) { 
            
            Console.WriteLine(el);}
        }


    }






}




namespace projekt
{
    internal class Robot
    {
        public int weight;


        public string name;


        public byte[] cootdinates;


        public Robot(string _name, int _weight, byte[] _cootdinates) {
            Console.WriteLine("Object has been created");


            setValues(_name, _weight, _cootdinates);
        }


        public Robot()
        {
            
        }


        public void setValues(string _name, int _weight, byte[] _cootdinates)
        {
            name = _name;


            weight = _weight;


            cootdinates = _cootdinates;
        }


        public void printValues ()
        {
            Console.WriteLine("Name: " + name + "Weight: " + weight);


            foreach (var el in cootdinates) { 
            
            Console.WriteLine(el);}
        }


    }






}




internal class Program
{
    static void Main(string[] args)
    {


        Robot bot = new Robot("Bot", 12, new byte[] { 0, 0, 0 });


        
        bot.printValues();


        Robot killer = new Robot();


        killer.setValues("Killer", 12, new byte[] { 0, 0, 10 });


        bot.printValues();


        
    }
}

 public void setValues(string name, int weight, byte[] cootdinates)
        {
            this.name = name;

            this.weight = weight;

            this.cootdinates = cootdinates;
            
            
        }
public int Weight {
        get
            {
                
                return this.weight;
            }
            set {
                if(value < 1)
                this.weight = 1;

                else 
                    this.Weight = value; 
            }
        }

internal class Class1 : Robot
    {
        public Class1() {
        }

        public int Heals { get; set; }
        public Class1(string name, int weight, byte[] coordinates, int heals) : base()
        {
            this.Heals = heals;
        }
            

    }

public string Name {
            get {
                return name;
                    }
            private set { }
        }


List<Robot> robots = new List<Robot>();
        robots.Add(new Robot("Alex", 100, new byte[] { 14, 10,12}));
        robots.Add(new Robot("Bob", 660, new byte[] { 66, 10, 12 }));
        robots.Add(new Robot("Mike", 400, new byte[] { 34, 10, 12 }));
        robots.Add(new Robot("Lolo", 300, new byte[] { 37, 10, 12 }));


        foreach (Robot obj in robots) {
        Console.WriteLine(obj.Name);
        }


List<Robot> robots = new List<Robot>();
        robots.Add(new Robot("Alex", 100, new byte[] { 14, 10,12}));
        robots.Add(new Robot("Bob", 660, new byte[] { 66, 10, 12 }));
        robots.Add(new Robot("Mike", 400, new byte[] { 34, 10, 12 }));
        robots.Add(new Robot("Lolo", 300, new byte[] { 37, 10, 12 }));


        

        Robot robot = null;

        foreach (Robot obj in robots) { 
        if (obj.name == "Bob") {
                
                newRobot = obj as Robot;
            }

        Console.WriteLine(obj.name);

        }

vList<Killer> robots = new List<Killer>();
        robots.Add(new Killer("Alex", 100, new byte[] { 14, 10,12}, 100));
        robots.Add(new Killer("Bob", 660, new byte[] { 66, 10, 12 }, 100));
        robots.Add(new Killer("Mike", 400, new byte[] { 34, 10, 12 }, 100));
        robots.Add(new Killer("Lolo", 300, new byte[] { 37, 10, 12 }, 100));

        Robot newRobot = null;
        foreach (Killer obj in robots)
        {
            if(obj.name == "Alex")
            {
                newRobot = obj as Robot;
            }
            Console.WriteLine(obj.name);
        }



List<Killer> robots = new List<Killer>();
        robots.Add(new Killer("Alex", 100, new byte[] { 14, 10,12}, 100));
        robots.Add(new Killer("Bob", 660, new byte[] { 66, 10, 12 }, 100));
        robots.Add(new Killer("Mike", 400, new byte[] { 34, 10, 12 }, 100));
        robots.Add(new Killer("Lolo", 300, new byte[] { 37, 10, 12 }, 100));

        Robot newRobot = null;
        foreach (Killer obj in robots)
        {
            if(obj.name == "Alex")
            {
                newRobot = obj as Robot;
            }
            Console.WriteLine(obj is float);
        }
        

        
    }

public override void printValues()
        {
            base.printValues();

            Console.WriteLine("Heals: " + Heals);
        }


namespace projekt 
{
    interface Irun
    {
        float speed { get; set; }

        void RobotRun()
        {
            
        }
    }
}

interface IJump

{
    float y { get; set; }

    void Jump(float x);

}
