with Ada.Text_IO;use Ada.Text_IO;
with EmployeesPackage; use EmployeesPackage;

procedure Main is
    employees : EmployeesList :=
       (
        (name             => "Christian ",
         func             => BOSS,
         birthdate        => (1_971,01,01),
         salary           => 10.0*SMIC,
         pro_vehicle      => CAR,
         business_expense => 10.0*SMIC,
         cell_plan        => True,
         personal_vehicle => CAR),
        (name             => "Robin     ",
         func             => HR,
         personal_vehicle => SCOOTER,
         birthdate        => (1_969, 02, 06),
         salary           => 3.0*SMIC,
         food_voucher     => 20),
        (name             => "Luffy     ",
         func             => SALES,
         birthdate        => (1_971, 05, 05),
         salary           => 4.2*SMIC,
         pro_vehicle      => PUBLIC_TRANSPORT,
         business_expense => 4.2*SMIC,
         cell_plan        => False,
         personal_vehicle => PUBLIC_TRANSPORT),
        (name => "Sangi     ",
         func             => SALARIED,
         birthdate        => (1_971, 03, 02),
         salary           => SMIC,
         food_voucher     => 20,
         personal_vehicle => PUBLIC_TRANSPORT)
       );

begin
   Print_All_Employees (employees);
   --Give_Raise(employees, "Christian ", 10.0);
   Quick_Sort(employees);
   Put_Line("----------------------------------------");
   Print_All_Employees (employees);
   --Set_Salary(employees(1),-1.0);
   --Print_Employee(Employees(1));



end Main;
