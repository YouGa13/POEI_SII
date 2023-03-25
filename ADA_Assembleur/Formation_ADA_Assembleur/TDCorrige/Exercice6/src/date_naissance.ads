package date_naissance is

   type Date is record
      Jour  : Natural range 1 .. 31;
      Mois  : Natural range 1 .. 12;
      Annee : Natural range 1_900 .. 2_100;
   end record;

end date_naissance;
