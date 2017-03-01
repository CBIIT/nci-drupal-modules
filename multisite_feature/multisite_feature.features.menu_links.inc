<?php
/**
 * @file
 * multisite_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function multisite_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about-cbiit:node/1.
  $menu_links['main-menu_about-cbiit:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'About CBIIT',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_about-cbiit:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_access-and-accounts:node/1.
  $menu_links['main-menu_access-and-accounts:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Access and Accounts',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_access-and-accounts:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_our-services:node/1',
  );
  // Exported menu link: main-menu_business-applications:node/1.
  $menu_links['main-menu_business-applications:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Business Applications',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_business-applications:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'main-menu_our-services:node/1',
  );
  // Exported menu link: main-menu_email-communication:node/1.
  $menu_links['main-menu_email-communication:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Email Communication',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_email-communication:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_our-services:node/1',
  );
  // Exported menu link: main-menu_equipment-and-software:node/1.
  $menu_links['main-menu_equipment-and-software:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Equipment and Software',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_equipment-and-software:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_our-services:node/1',
  );
  // Exported menu link: main-menu_grants-management:node/1.
  $menu_links['main-menu_grants-management:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Grants Management',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_grants-management:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'main-menu_our-services:node/1',
  );
  // Exported menu link: main-menu_hosting-network-databases-and-storage:node/1.
  $menu_links['main-menu_hosting-network-databases-and-storage:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Hosting, Network, Databases, and Storage',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_hosting-network-databases-and-storage:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'main-menu_our-services:node/1',
  );
  // Exported menu link: main-menu_how-do-i:node/1.
  $menu_links['main-menu_how-do-i:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'How do I?',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_how-do-i:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_informatics-and-high-performance-computing:node/1.
  $menu_links['main-menu_informatics-and-high-performance-computing:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Informatics and High Performance Computing',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_informatics-and-high-performance-computing:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'main-menu_our-services:node/1',
  );
  // Exported menu link: main-menu_news--events:node/1.
  $menu_links['main-menu_news--events:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'News & Events',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_news--events:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_our-services:node/1.
  $menu_links['main-menu_our-services:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Our Services',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_our-services:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_policies:node/1.
  $menu_links['main-menu_policies:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Policies',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_policies:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: main-menu_security:node/1.
  $menu_links['main-menu_security:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Security',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_security:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'main-menu_our-services:node/1',
  );
  // Exported menu link: main-menu_submit-a-ticket:submit-ticket.
  $menu_links['main-menu_submit-a-ticket:submit-ticket'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'submit-ticket',
    'router_path' => 'submit-ticket',
    'link_title' => 'Submit a Ticket',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_submit-a-ticket:submit-ticket',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-external-menu_national-cancer-institute:node/1.
  $menu_links['menu-external-menu_national-cancer-institute:node/1'] = array(
    'menu_name' => 'menu-external-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'National Cancer Institute',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-external-menu_national-cancer-institute:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-external-menu_national-institutes-of-health:node/1.
  $menu_links['menu-external-menu_national-institutes-of-health:node/1'] = array(
    'menu_name' => 'menu-external-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'National Institutes of Health',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-external-menu_national-institutes-of-health:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-external-menu_us-department-of-health-and-human-services:node/1.
  $menu_links['menu-external-menu_us-department-of-health-and-human-services:node/1'] = array(
    'menu_name' => 'menu-external-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'U.S. Department of Health and Human Services',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-external-menu_us-department-of-health-and-human-services:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-external-menu_usagov:node/1.
  $menu_links['menu-external-menu_usagov:node/1'] = array(
    'menu_name' => 'menu-external-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'USA.gov',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-external-menu_usagov:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-quick-support_common-issues:node/1.
  $menu_links['menu-quick-support_common-issues:node/1'] = array(
    'menu_name' => 'menu-quick-support',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Common Issues',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-quick-support_common-issues:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-quick-support_informatics-consult:node/1.
  $menu_links['menu-quick-support_informatics-consult:node/1'] = array(
    'menu_name' => 'menu-quick-support',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Informatics Consult',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-quick-support_informatics-consult:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-quick-support_new-employees:node/1.
  $menu_links['menu-quick-support_new-employees:node/1'] = array(
    'menu_name' => 'menu-quick-support',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'New Employees',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-quick-support_new-employees:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About CBIIT');
  t('Access and Accounts');
  t('Business Applications');
  t('Common Issues');
  t('Email Communication');
  t('Equipment and Software');
  t('Grants Management');
  t('Hosting, Network, Databases, and Storage');
  t('How do I?');
  t('Informatics Consult');
  t('Informatics and High Performance Computing');
  t('National Cancer Institute');
  t('National Institutes of Health');
  t('New Employees');
  t('News & Events');
  t('Our Services');
  t('Policies');
  t('Security');
  t('Submit a Ticket');
  t('U.S. Department of Health and Human Services');
  t('USA.gov');

  return $menu_links;
}
