@isTest
private class DailyLeadProcessorTest {
    public static String CRON_EXP = '0 0 0 18 6 ? 2023'; // Dummy CRON expression:  on June 18 2023.
    
     // The Job immediately after Test.stopTest().
    static testmethod void testScheduledJob() {
        List<Lead> leads = new List<lead>();
        
        for (Integer i=0; i<200; i++) {
            Lead L = new Lead(
                FirstName = 'First ' + i,
                LastName = 'LastName',
                Company = 'The Inc'
            );
            leads.add(l);
        }
        insert leads;
        
        Test.startTest();
        String jobId = System.schedule('ScheduledApexTest',
            CRON_EXP,
            new DailyLeadProcessor());
        
        Test.stopTest();
        // Now that the scheduled job has executed,check that we have 200 Leads
		List<Lead> checkleads = new List<lead>();        
        checkleads = [SELECT Id FROM Lead  WHERE LeadSource = 'Dreamforce' and Company =  'The Inc'];   
        System.assertEquals(200,
            checkleads.size(),
            'Leads were not created yet');
    }
}
