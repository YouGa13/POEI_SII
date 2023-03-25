package identite_employe.info_association is

   type info_benevole_association is new InfoEmploye with null record;

   procedure donnation (info : info_benevole_association; don : Float);

end identite_employe.info_association;
