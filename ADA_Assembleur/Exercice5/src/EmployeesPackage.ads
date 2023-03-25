with Ada.Text_IO; use Ada.Text_IO;

package EmployeesPackage is
   pragma Assertion_Policy(Check);
   
   SMIC : constant := 1_709.28;
   
   type Date is record
        year  : Natural range 1_900 .. 2_100;
        month : Natural range 1 .. 12;
        day   : Natural range 1 .. 31;
   end record;
   
   type EmployeeFunction is (BOSS, SALES, HR, SALARIED);
   
   type Vehicle is (CAR, BIKE, SCOOTER, BICYCLE, PUBLIC_TRANSPORT);
   
   type Employee (func : EmployeeFunction := SALARIED) is record
       name             : String(1..10);
       birthdate        : Date;
       salary           : Float := SMIC;
       personal_vehicle : Vehicle;
       case func is
           when BOSS | SALES =>
               pro_vehicle      : Vehicle;
               business_expense : Float;
               cell_plan        : Boolean;
           when HR | SALARIED =>
               food_voucher : Natural;
       end case;
    end record;
    
    type EmployeesList is array (Positive range <>) of Employee;

    procedure Display_Date (ADate : Date);
    procedure Print_Employee (Personn : in Employee);
    procedure Print_All_Employees (Company : in EmployeesList);
    procedure Set_Salary (Personn : in out Employee; Salary : in Float)
      with Pre => (Salary > 0.0);
    procedure Give_Raise (Company : in out EmployeesList; who : in String; percentage : in float);
    function Get_Min_Boss_Salary (Company : in EmployeesList) return Float;
    function Get_Max_Non_Boss_Salary(Company : in EmployeesList) return Float;
    function "<" (L, R : Employee) return Boolean;
    procedure Quick_Sort(Company : in out EmployeesList);
        
end EmployeesPackage;
