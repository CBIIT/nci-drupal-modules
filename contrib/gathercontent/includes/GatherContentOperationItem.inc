<?php

class GatherContentOperationItem extends Entity {
  public function save() {
    if (empty($this->created)) {
      $this->created = REQUEST_TIME;
    }
    
    $this->changed = REQUEST_TIME;
    
    return parent::save(); 
  }
  
}
