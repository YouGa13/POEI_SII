with Ada.Text_IO;             use Ada.Text_IO;
with employe_de_l_entreprise; use employe_de_l_entreprise;
with filtre_nom_employe; use filtre_nom_employe;
procedure Main is

   InfoEntreprise : T_Info :=
     ((Commercial, Nom => "DUPOND    ", DateAnniversaire => (20, 10, 2_012),
       Salaire         => 2_000.0, TypeVehicule => Voiture,
       AvantageVoiture => Professionnelle, Frais => 10.2, ForfaitTel => True),
      (Employe, Nom    => "MARTIN    ", DateAnniversaire => (12, 06, 2_015),
       Salaire         => 2_150.0, TypeVehicule => Moto,
       AvantageVoiture => Personnelle, TR => 10.0),
      (RH, Nom         => "BERNARD   ", DateAnniversaire => (12, 06, 1_975),
       Salaire         => SMIC, TypeVehicule => Trottinette,
       AvantageVoiture => Personnelle, TR => 10.0),
      (Patron, Nom     => "JEAN      ", DateAnniversaire => (12, 06, 1_975),
       Salaire         => 4_005.0, TypeVehicule => Voiture,
       AvantageVoiture => Professionnelle, Frais => 10.2, ForfaitTel => True));

   sal_data : Float := 3_005.0;
   table_data : InfoEmploye := (Commercial, Nom => "DUPOND    ", DateAnniversaire => (20, 10, 2_012),
       Salaire         => 2_000.0, TypeVehicule => Voiture,
       AvantageVoiture => Professionnelle, Frais => 10.2, ForfaitTel => True);


begin

   Tri_salaire(InfoEntreprise);
   Tri_nom(InfoEntreprise);
   update_salaire(sal_data, table_data);
   afficher_salaire(InfoEntreprise);

   Put_Line ( "modif : " & table_data.Salaire'Image);

   afficher_employe_tri_nom(InfoEntreprise);

end Main;
