with Ada.Text_IO;                       use Ada.Text_IO;
with Ada.Exceptions;                    use Ada.Exceptions;
with identite_employe.info_entreprise;  use identite_employe.info_entreprise;
with identite_employe.info_association; use identite_employe.info_association;
procedure Main is

   InfoEntreprise : T_Info_Employe :=
     ((Fct => Commercial, Nom => "DUPOND    ", Prenom => "Pierre    ",
       DateAnniversaire => (20, 10, 2_012), Salaire => 2_000.0,
       TypeVehicule     => Voiture, AvantageVoiture => Professionnelle),
      (Fct => Employe, Nom => "MARTIN    ", Prenom => "Patrick   ",
       DateAnniversaire => (08, 03, 2_015), Salaire => 2_150.0,
       TypeVehicule     => Moto, AvantageVoiture => Personnelle),
      (Fct              => RH, Nom => "BERNARD   ", Prenom => "Jean      ",
       DateAnniversaire => (12, 09, 1_975), Salaire => SMIC,
       TypeVehicule     => Trottinette, AvantageVoiture => Personnelle),
      (Fct              => Patron, Nom => "JEAN      ", Prenom => "Olivier   ",
       DateAnniversaire => (25, 06, 1_965), Salaire => 4_005.0,
       TypeVehicule     => Voiture, AvantageVoiture => Professionnelle));

   InfoBenevola : info_benevole_association :=
     (Nom              => "MOULIN    ", Prenom => "Jean      ",
      DateAnniversaire => (20, 10, 1_912));

begin
   AfficheListe (InfoEntreprise);
   Augmentation
     (InfoE         => InfoEntreprise, quidoncNom => "MARTIN    ",
      quidoncPrenom => "Patrick   ", Pourcentage => 0.025);
   InfoEntreprise :=
     Augmentation
       (InfoE         => InfoEntreprise, quidoncNom => "BERNARD   ",
        quidoncPrenom => "Jean      ", Pourcentage => 0.1);
   Augmentation
     (InfoE         => InfoEntreprise, quidoncNom => "JEAN      ",
      quidoncPrenom => "Olivier   ", Pourcentage => 0.125);
   TriNom (Info => InfoEntreprise);
   AfficheListe (InfoEntreprise);
   donnation (info => InfoBenevola, don => 100.0);

end Main;
